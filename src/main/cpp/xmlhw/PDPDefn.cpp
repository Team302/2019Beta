
//====================================================================================================================================================
// Copyright 2019 Lake Orion Robotics FIRST Team 302
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
// OR OTHER DEALINGS IN THE SOFTWARE.
//====================================================================================================================================================

//========================================================================================================
/// PDPDefn.cpp
//========================================================================================================
///
/// File Description:
///     XML parsing for the PDP node in the Robot definition xml file.  Upon successful parsing, it will
///     create a PDP singleton object.
///     The parsing leverages the 3rd party Open Source Pugixml library (https://pugixml.org/).
///
//========================================================================================================

// C++ Includes
#include <iostream>
#include <memory>

// FRC includes
#include <frc/PowerDistributionPanel.h>

// Team 302 includes
#include <hw/DragonPDP.h>
#include <utils/HardwareIDValidation.h>
#include <utils/Logger.h>
#include <xmlhw/PDPDefn.h>

// Third Party Includes
#include <pugixml/pugixml.hpp>

using namespace frc;
using namespace pugi;
using namespace std;



///-----------------------------------------------------------------------
/// Method:      ParseXML
/// Description: Parse a pcm XML element and create a PowerDistributionPanel*
///              from its definition.
///
///<!-- ====================================================
///     PDP (power distribution panel)
///     ==================================================== -->
///<!ELEMENT pdp EMPTY>
///<!ATTLIST pdp
///          canId             (  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |
///                              10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 |
///                              20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 |
///                              30 | 31 | 32 | 33 | 34 | 35 | 36 | 37 | 38 | 39 |
///                              40 | 41 | 42 | 43 | 44 | 45 | 46 | 47 | 48 | 49 |
///                              50 | 51 | 52 | 53 | 54 | 55 | 56 | 57 | 58 | 59 |
///                              60 | 61 | 62 ) "0"
///>
///
/// Returns:     shared_ptr<PowerDistributionPanel>   PDP object
///-----------------------------------------------------------------------
shared_ptr<PowerDistributionPanel> PDPDefn::ParseXML
(
    xml_node      PDPNode           /// <I> - PDP node in the XML file
)
{
    // initialize output
    shared_ptr<PowerDistributionPanel> pdp;

    // initialize attributes to default values
    int canID = 0;

    bool hasError = false;

    // parse/validate the PDP XML node
    for (xml_attribute attr = PDPNode.first_attribute(); attr && !hasError; attr = attr.next_attribute())
    {
        if ( strcmp( attr.name(), "canId" ) == 0 )
        {
            canID = attr.as_int();
            hasError = HardwareIDValidation::ValidateCANID( canID, string( "PDPDefn::ParseXML" ) );
        }
        else
        {
            string msg = "unknown attribute ";
            msg += attr.name();
            Logger::GetLogger()->LogError( "PDPDefn::ParseXML", msg );
            hasError = true;
        }
    }

    // If no errors, create the object
    if ( !hasError )
    {
        pdp = DragonPDP::GetInstance()->CreatePDP( canID );
    }
    return pdp;
}


