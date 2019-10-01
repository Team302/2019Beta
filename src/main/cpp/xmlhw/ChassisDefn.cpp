
///====================================================================================================================================================
/// Copyright 2019 Lake Orion Robobitcs FIRST Team 302
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
/// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
/// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
/// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
/// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
/// OR OTHER DEALINGS IN THE SOFTWARE.
///====================================================================================================================================================

///========================================================================================================
// ChassisDefn. 
///========================================================================================================
//
// Description: Create a chassis from an XML definition
//
// <!ELEMENT chassis (motor*) >
// <!ATTLIST chassis
//           wheelDiameter     CDATA #REQUIRED
//           wheelBase         CDATA #REQUIRED
//           track             CDATA #REQUIRED
// >
//
// type matches CHASSIS_TYPE enum found in ChassisFactory.h
//
// Wheel Base is front-back distance between wheel centers
//
// Track is the distance between wheels on an "axle"
//
///========================================================================================================

// C++ includes
#include <iostream>

// FRC includes
#include <frc/SmartDashboard/SmartDashboard.h>

// Team302 includes
//#include <subsys/chassis/DragonChassis.h>
//#include <hw/DragonTalon.h>
#include <xmlhw/ChassisDefn.h>
#include <xmlhw/MotorDefn.h>
#include <xmlhw/PIDDefn.h>

// Third Party includes
#include <pugixml/pugixml.hpp>


using namespace frc;



///================================================================================================
/// Method:      ParseXML
/// Description: Parse the chassie element (and it children) from the chassis.  When this is done
//				 a dragon chassis exists that can be retrieved from the factory.
/// Returns:     void
///================================================================================================
void ChassisDefn::ParseXML
(
	pugi::xml_node      chassisNode
)
{
    float wheelDiameter	= 0.0;
    float wheelBase 	= 0.0;
    float track 		= 0.0;
    bool hasError 		= false;

    //--------------------------------------------------------------------------------------------
    // process attributes
    //--------------------------------------------------------------------------------------------
    for (pugi::xml_attribute attr = chassisNode.first_attribute(); attr; attr = attr.next_attribute())
    {
        if ( strcmp( attr.name(), "wheelDiameter" ) == 0 )
        {
        	wheelDiameter = attr.as_float();
        }
        else if ( strcmp( attr.name(), "wheelBase" ) == 0 )
        {
        	wheelBase = attr.as_float();
        }
        else if ( strcmp( attr.name(), "track" ) == 0 )
        {
        	track = attr.as_float();
        }
        else
        {
            std::cout << "==>> ChassisDefn:  Invalid attribute "  << attr.name() << "\n";
            hasError = true;
        }
    }

    //--------------------------------------------------------------------------------------------
    // Process child element nodes
    //--------------------------------------------------------------------------------------------
    std::vector<PIDData*> pidControlVector;
    for (pugi::xml_node child = chassisNode.first_child(); child; child = child.next_sibling())
    {
    	if ( strcmp( child.name(), "motor") == 0 )
    	{
    		MotorDefn::ParseXML( child );
    	}
        else if ( strcmp( child.name(), "PID") == 0 )
        {
            pidControlVector.emplace_back( PIDDefn::ParseXML( child ) );
        }
    	else
    	{
            std::cout << "==>> ChassisDefn:  unknown child "  << child.name() << "\n";
    	}
    }


    //--------------------------------------------------------------------------------------------
    // create chassis instance
    //--------------------------------------------------------------------------------------------
    if ( !hasError )
    {
        /// TODO:: Call the factory
    }
}

