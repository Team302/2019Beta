
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
/// AnalogInputFactory.cpp
///========================================================================================================
///
/// File Description:
///     This controls the creation of analog inputs
///
///========================================================================================================

// C++ Includes
#include <iostream>

// FRC includes

// Team 302 includes
#include <hw/AnalogInputFactory.h>
#include <hw/DragonAnalogInput.h>
//#include <hw/DragonAngleSensorFactory.h>


// Third Party Includes




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


///=====================================================================================
/// Method:         CreateInput
/// Description:    Create the requested analog input
/// Returns:        IMechanism*     pointer to the mechanism or nullptr if mechanism 
///                                 doesn't exist and cannot be created.
///=====================================================================================
DragonAnalogInput* AnalogInputFactory::CreateInput
(
    DragonAnalogInput::ANALOG_SENSOR_TYPE			type,
    int 						                    analogID,
    float						                    voltageMin,
    float						                    voltageMax,
    float 						                    outputMin,
    float						                    outputMax
)
{
    DragonAnalogInput* sensor = nullptr;
    switch ( type )
    {
        /**
        case DragonAnalogInput::ANALOG_GENERAL:
            sensor = m_general == nullptr ? new DragonAnalogInput( type, analogID, voltageMin, voltageMax, outputMin, outputMax ) : m_general;
            break;

        case DragonAnalogInput::ANALOG_GYRO:
            sensor = m_gyro = nullptr ? new DragonAnalogInput( type, analogID, voltageMin, voltageMax, outputMin, outputMax ) : m_gyro;
            break;
        **/
        case DragonAnalogInput::EXTENDER_POTENTIOMETER:
            sensor = m_potentiometer == nullptr ? new DragonAnalogInput( type, analogID, voltageMin, voltageMax, outputMin, outputMax ) : m_potentiometer;
            // TODO: construct an angle sensor
            break;
        /**
        case DragonAnalogInput::PRESSURE_GAUGE:
            sensor = m_pressureGauge == nullptr ? new DragonAnalogInput( type, analogID, voltageMin, voltageMax, outputMin, outputMax ) : m_pressureGauge;
            break;
        **/
        default:
            std::cout << "==>>AnalogInputFactory::CreateInput unknown type " << type << std::endl;
            break;
    }
    return sensor;
}

///=====================================================================================
/// Method:         GetInput
/// Description:    Get the requested analog input
/// Returns:        DragonAnalogInput*     pointer to the analog input or nullptr if it 
///                                 	   doesn't exist 
///=====================================================================================
DragonAnalogInput* AnalogInputFactory::GetInput
(
    DragonAnalogInput::ANALOG_SENSOR_TYPE			type
)
{
    DragonAnalogInput* sensor = nullptr;
    switch ( type )
    {
        case DragonAnalogInput::EXTENDER_POTENTIOMETER:
            sensor = m_potentiometer;
            // TODO: construct an angle sensor
            break;
        default:
            std::cout << "==>>AnalogInputFactory::GetInput unknown type " << type << std::endl;
            break;
    }
    return sensor;
}

AnalogInputFactory::AnalogInputFactory()
{
    m_general = nullptr;
    m_gyro = nullptr;
    m_potentiometer = nullptr;
    m_pressureGauge = nullptr;
}

AnalogInputFactory::~AnalogInputFactory()
{
    if ( m_general != nullptr )
    {
        delete m_general;
        m_general = nullptr;
    }    
    if ( m_gyro != nullptr )
    {
        delete m_gyro;
        m_gyro = nullptr;
    }    
    if ( m_potentiometer != nullptr )
    {
        delete m_potentiometer;
        m_potentiometer = nullptr;
    }    
    if ( m_pressureGauge != nullptr )
    {
        delete m_pressureGauge;
        m_pressureGauge = nullptr;
    }
}
