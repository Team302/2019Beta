
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
#include <memory>

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
#include <utils/Logger.h>

// Third Party Includes
#include <pugixml/pugixml.hpp>

using namespace frc;
using namespace pugi;
using namespace std;


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
    xml_document doc;
    xml_parse_result result = doc.load_file(filename);

    // if it is good
    if (result)
    {
        unique_ptr<ChassisDefn> chassisXML;
        unique_ptr<MechanismDefn> mechanismXML;
     //   unique_ptr<PCMDefn> pcmXML;
        unique_ptr<PDPDefn> pdpXML;
        unique_ptr<PigeonDefn> pigeonXML;
        unique_ptr<LidarDefn> lidarXML;
        unique_ptr<LEDDefn> ledXML;
        unique_ptr<CameraDefn> cameraXML;

        // get the root node <robot>
        xml_node parent = doc.root();
        for (xml_node node = parent.first_child(); node; node = node.next_sibling())
        {
            // loop through the direct children of <robot> and call the appropriate parser
            for (xml_node child = node.first_child(); child; child = child.next_sibling())
            {
                if (strcmp(child.name(), "chassis") == 0)
                {
                    chassisXML = chassisXML == nullptr ? make_unique<ChassisDefn>() : chassisXML;
                    if ( chassisXML != nullptr )
                    {
                        chassisXML->ParseXML(child);
                    }
                    else
                    {
                        Logger::GetLogger()->Log( "RobotDefn::ParseXML", "Unable to create ChassisDefn" );
                    }

                }
                else if (strcmp(child.name(), "mechanism") == 0)
                {
                    mechanismXML = ( mechanismXML == nullptr ) ? make_unique<MechanismDefn>() : mechanismXML;
                    if ( mechanismXML != nullptr )
                    {
                        mechanismXML->ParseXML(child);
                    }
                    else
                    {
                        Logger::GetLogger()->Log( "RobotDefn::ParseXML", "Unable to create MechanismDefn" );
                    }
                }
                else if ( strcmp( child.name(), "pcm") == 0 )
                {
//                    PCMDefn::ParseXML( child );
                }
                else if (strcmp(child.name(), "pdp") == 0)
                {
                    pdpXML = ( pdpXML == nullptr ) ? make_unique<PDPDefn>() : pdpXML;
                    if ( pdpXML != nullptr )
                    {
                        pdpXML->ParseXML(child);
                    }
                    else
                    {
                        Logger::GetLogger()->Log( "RobotDefn::ParseXML", "Unable to create PDPDefn" );
                    }
                }
                else if (strcmp(child.name(), "pigeon") == 0)
                {
                    pigeonXML = ( pigeonXML == nullptr ) ? make_unique<PigeonDefn>() : pigeonXML;
                    if ( pigeonXML != nullptr )
                    {
                        pigeonXML->ParseXML(child);
                    }
                    else
                    {
                        Logger::GetLogger()->Log( "RobotDefn::ParseXML", "Unable to create PigeonDefn" );
                    }
                }
                else if ( strcmp( child.name(), "lidar") == 0 )
                {
                    lidarXML = ( lidarXML == nullptr ) ? make_unique<LidarDefn>() : lidarXML;
                    if ( lidarXML != nullptr )
                    {
                        lidarXML->ParseXML(child);
                    }
                    else
                    {
                        Logger::GetLogger()->Log( "RobotDefn::ParseXML", "Unable to create LidarDefn" );
                    }
                }
                else if (strcmp(child.name(), "camera") == 0)
                {
                    cameraXML = ( cameraXML == nullptr ) ? make_unique<CameraDefn>() : cameraXML;
                    if ( cameraXML != nullptr )
                    {
                        cameraXML->ParseXML(child);
                    }
                    else
                    {
                        Logger::GetLogger()->Log( "RobotDefn::ParseXML", "Unable to create CameeraDefn" );
                    }
                }
                else if (strcmp(child.name(), "led") == 0)
                {
                    ledXML = ( ledXML == nullptr ) ? make_unique<LEDDefn>() : ledXML;
                    if ( ledXML != nullptr )
                    {
                        ledXML->ParseXML(child);
                    }
                    else
                    {
                        Logger::GetLogger()->Log( "RobotDefn::ParseXML", "Unable to create LDEDefn" );
                    }
                }
                else
                {
                    string msg = "unknown child ";
                    msg += child.name();
                    Logger::GetLogger()->Log( "RobotDefn::ParseXML", msg );
                }
            }
        }
    }
    else
    {
        string msg = "XML [";
        msg += filename;
        msg += "] parsed with errors, attr value: [";
        msg += doc.child( "prototype" ).attribute( "attr" ).value();
        msg += "]";
        Logger::GetLogger()->Log( "RobotDefn::ParseXML (1) ", msg );

        msg = "Error description: ";
        msg += result.description();
        Logger::GetLogger()->Log( "RobotDefn::ParseXML (2) ", msg );

        msg = "Error offset: ";
        msg += result.offset;
        msg += " error at ...";
        msg += filename;
        msg += result.offset;
        Logger::GetLogger()->Log( "RobotDefn::ParseXML (3) ", msg );
    }
}
