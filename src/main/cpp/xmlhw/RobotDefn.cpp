
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
/// RobotDefn.cpp
///========================================================================================================
///
/// File Description:
///     Top-level XML parsing file for the robot.  This definition will construct the motor controllers,
///     sensors, chassis and mechanisms from an XML file.  This parsing leverages the 3rd party Open Source
///     Pugixml library (https://pugixml.org/).
///
///     This parsing code will call the classes/methods to parse the lower-level objects.  When the parsing
///     has been completed, the robot hardware will be defined.
///
///     The robot definition XML file is:  /home/lvuser/config/robot.xml
///
///========================================================================================================

// C++ Includes
#include <iostream>

// FRC includes

// Team 302 includes
#include <xmlhw/CameraDefn.h>
#include <xmlhw/ChassisDefn.h>
#include <xmlhw/RobotDefn.h>
#include <xmlhw/LidarDefn.h>
#include <xmlhw/MechanismDefn.h>
//#include <xmlhw/PCMDefn.h>
#include <xmlhw/LEDDefn.h>
#include <xmlhw/PDPDefn.h>
#include <xmlhw/PigeonDefn.h>

// Third Party Includes
#include <pugixml/pugixml.hpp>

using namespace frc;
//-----------------------------------------------------------------------
// Method:      ParseXML
// Description: Parse a robot.xml file
// Returns:     void
//-----------------------------------------------------------------------
void RobotDefn::ParseXML()
{
    // set the file to parse
    const char *filename = "/home/lvuser/config/robot.xml";

    // load the xml file into memory (parse it)
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(filename);

    // if it is good
    if (result)
    {
        // get the root node <robot>
        pugi::xml_node parent = doc.root();
        for (pugi::xml_node node = parent.first_child(); node; node = node.next_sibling())
        {
            // loop through the direct children of <robot> and call the appropriate parser
            for (pugi::xml_node child = node.first_child(); child; child = child.next_sibling())
            {
                if (strcmp(child.name(), "chassis") == 0)
                {
                    ChassisDefn::ParseXML(child);
                }
                else if (strcmp(child.name(), "mechanism") == 0)
                {
                    MechanismDefn::ParseXML(child);
                }
                else if ( strcmp( child.name(), "pcm") == 0 )
                {
//                    PCMDefn::ParseXML( child );
                }
                else if (strcmp(child.name(), "pdp") == 0)
                {
                    PDPDefn::ParseXML( child );
                }
                else if (strcmp(child.name(), "pigeon") == 0)
                {
                    PigeonDefn::ParseXML(child);
                }
                else if ( strcmp( child.name(), "lidar") == 0 )
                {
                     LidarDefn::ParseXML( child );
                }
                else if (strcmp(child.name(), "camera") == 0)
                {
                    CameraDefn::ParseXML( child );
                }
                else if (strcmp(child.name(), "led") == 0)
                {
                    LEDDefn::ParseXML(child);
                }
                else
                {
                    std::cout << "==>>RobotDefn::ParseXML unknown robot child " << child.name() << std::endl;
                }
            }
        }
    }
    else
    {
        std::cout << "XML [" << filename << "] parsed with errors, attr value: [" << doc.child("prototype").attribute("attr").value() << "]" << std::endl;
        std::cout << "Error description: " << result.description() << std::endl;
        std::cout << "Error offset: " << result.offset << " (error at [..." << (filename + result.offset) << "]" << std::endl;
    }
}
