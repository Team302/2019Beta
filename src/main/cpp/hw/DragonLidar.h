
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



#pragma once

// C++ Includes
#include <memory>
#include <string>
#include <vector>

// FRC includes
#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableEntry.h>

// Team 302 includes
#include <hw/IDragonSensor.h>
#include <hw/IDragonDistanceSensor.h>

// Third Party Includes

//Includes
#include <frc/Counter.h>
#include <frc/DigitalOutput.h>

/*
 * This class takes a LIDAR that is connected to a digital input on the roborio using PWM.
 * We measure the high pulse length and convert it to a distance in GetDistance()
 *
 * the trigger pin is just used to initialize the lidar. It shouldn't have to be called periodically.
 */

class DragonLidar : public IDragonSensor, IDragonDistanceSensor
{
    public:
        ///-----------------------------------------------------------------------------------
        /// Method:         DragonLidar (constructor)
        /// Description:    Create the object
        ///-----------------------------------------------------------------------------------
        DragonLidar() = delete;
        DragonLidar
        (
            IDragonSensor::SENSOR_USAGE usage,
            int                         inputPin,
            int                         triggerPin
        );

        ///-----------------------------------------------------------------------------------
        /// Method:         ~DragonLidar (destructor)
        /// Description:    Delete the object
        ///-----------------------------------------------------------------------------------
        virtual ~DragonLidar() = default;

        ///-----------------------------------------------------------------------
        /// Method:      GetDistance
        /// Description: Return the measured distance in inches
        /// Returns:     double     Measured Distance
        ///-----------------------------------------------------------------------
        double GetDistance() const override;   // IDragonDistanceSensor


        ///-----------------------------------------------------------------------
        /// Method:      GetConfidence
        /// Description: Indicates how accurate the returned value is
        /// Returns:     double    0.0 == ignore (sensor has an error)
        ///                        1.0 == very confident 
        ///-----------------------------------------------------------------------
        double GetConfidence() const override; // IDragonSensor

        ///-----------------------------------------------------------------------
        /// Method:      GetUsage
        /// Description: Indicate what the sensor is used for
        /// Returns:     SENSOR_USAGE    sensor usage 
        ///-----------------------------------------------------------------------
        IDragonSensor::SENSOR_USAGE GetUsage() const override;

    private:
        IDragonSensor::SENSOR_USAGE                 m_usage;
        std::unique_ptr<frc::Counter>               m_pulseWidthCounter;
        std::unique_ptr<frc::DigitalOutput>         m_trigger;
};

