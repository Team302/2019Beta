
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
/// AnalogInputFactory.cpp
///========================================================================================================
///
/// File Description:
///     This controls the creation of analog inputs
///
///========================================================================================================

// C++ Includes
#include <algorithm>
#include <locale>
#include <map>
#include <memory>
#include <string>

// FRC includes

// Team 302 includes
#include <hw/AnalogInputFactory.h>
#include <hw/DragonAnalogInput.h>
//#include <hw/DragonAngleSensorFactory.h>
#include <utils/Logger.h>


// Third Party Includes


using namespace std;

///=====================================================================================
/// Method:         GetFactory
/// Description:    Find or create the analog input factory
/// Returns:        AnalogInputFactory* pointer to the factory
///=====================================================================================
AnalogInputFactory* AnalogInputFactory::m_factory = nullptr;
AnalogInputFactory* AnalogInputFactory::GetFactory()
{
	if ( AnalogInputFactory::m_factory == nullptr )
	{
		AnalogInputFactory::m_factory = new AnalogInputFactory();
	}
	return AnalogInputFactory::m_factory;
}

AnalogInputFactory::AnalogInputFactory( )
{
    CreateUsageMap();
}


void AnalogInputFactory::CreateUsageMap()
{
    m_usageMap["EXTENDER_POTENTIOMETER"]  = DragonAnalogInput::ANALOG_SENSOR_TYPE::EXTENDER_POTENTIOMETER;
    m_usageMap["PRESSURE_GAUGE"] = DragonAnalogInput::ANALOG_SENSOR_TYPE::PRESSURE_GAUGE;
}
///=====================================================================================
/// Method:         CreateInput
/// Description:    Create the requested analog input
/// Returns:        IMechanism*     pointer to the mechanism or nullptr if mechanism 
///                                 doesn't exist and cannot be created.
///=====================================================================================
shared_ptr<DragonAnalogInput> AnalogInputFactory::CreateInput
(
    string  usage,
    int 	analogID,
    float	voltageMin,
    float	voltageMax,
    float 	outputMin,
    float	outputMax
)
{
    shared_ptr<DragonAnalogInput> sensor;

    auto hasError = false;

    auto type = m_usageMap.find(usage)->second;
    switch ( type )
    {
        case DragonAnalogInput::ANALOG_SENSOR_TYPE::EXTENDER_POTENTIOMETER:
            sensor = make_shared<DragonAnalogInput>( type,
                                                     analogID,
                                                     voltageMin,
                                                     voltageMax,
                                                     outputMin,
                                                     outputMax );
            // TODO: Create an angle sensor + decorate it as a position sensor
            break;

        case DragonAnalogInput::ANALOG_SENSOR_TYPE::PRESSURE_GAUGE:
            sensor = make_shared<DragonAnalogInput> ( type,
                                                      analogID,
                                                      voltageMin,
                                                      voltageMax,
                                                      outputMin,
                                                      outputMax );
            break;

        default:
            hasError = true;
            string msg = "unknown type " + type;
            Logger::GetLogger()->Log( "AnalogInputFactory::CreateInput", msg );

    }
    return sensor;
}

