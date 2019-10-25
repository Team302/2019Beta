
///====================================================================================================================================================
/// Copyright 2019 Lake Orion Robotics FIRST Team 302
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

#pragma once

///========================================================================================================
/// Intake.h
///========================================================================================================
///
/// File Description:
///     This is the Intake Subsystem
///
///========================================================================================================

// C++ Includes

// FRC includes

// Team 302 includes
#include <hw/IDragonMotorController.h>
#include <subsys/IMechanism.h>

// Third Party Includes


///========================================================================================================
///  Class:         IMechanism
///  Description:   Interface for subsystems
///========================================================================================================
class Intake : public IMechanism
{
    public:

        ///==================================================================================
        /// method:         Intake <<constructor>>
        /// description:    Create the subobjects and initialize the Intake subsystem
        ///==================================================================================
        Intake();

        ///==================================================================================
        /// method:         ~Intake <<destructor>>
        /// description:    clean up memory when this object gets deleted
        ///==================================================================================
        virtual ~Intake();

        ///==================================================================================
        /// method:         GetType
        /// description:    Indicates this is the intake
        /// returns:        IMechanism::MECHANISM_TYPE::INTAKE
        ///==================================================================================
        IMechanism::MECHANISM_TYPE GetType() const override;


        ///==================================================================================
        /// method:         SetPercentOutput
        /// description:    Run intake in open loop (percent output)
        /// returns:        void
        ///==================================================================================
        void SetPercentOutput
        (
            double      value       /// <I> - percent output for the motor(s)
        ) override;


        ///==================================================================================
        /// method:         SetPosition
        /// description:    Run intake in closed loop position mode.  The value is in 
        ///                 degrees.  Since we don't have a sensor, this will run percent
        ///                 output in the direction specified.  We will use the standard unit
        ///                 circle for direction with negative being clockwise and positive
        ///                 being counter-clockwise.
        /// returns:        void
        ///==================================================================================
        void SetPosition 
        (
            double      pos       /// <I> - target position in degrees (rotating mechansim) 
        ) override;


        ///==================================================================================
        /// method:         GetCurrentPostion
        /// description:    Return the current position of the intake in degrees.  Since
        ///                 we don't have a sensor this will return -90 for clockwise rotations
        ///                 and 90 for counter-clockwise rotations.
        /// returns:        double  position in degrees (rotating mechansim)
        ///==================================================================================
        double GetCurrentPosition() const override;


        ///==================================================================================
        /// method:         GetTargetPostion
        /// description:    Return the target position of the intake.  Since
        ///                 we don't have a sensor this will return -90 for clockwise rotations
        ///                 and 90 for counter-clockwise rotations.
        /// returns:        double  position in degrees (rotating mechansim)
        ///==================================================================================
        double GetTargetPosition() const override;


        ///==================================================================================
        /// method:         SetSpeed
        /// description:    Run intake in closed loop velocity mode.  The value is in 
        ///                 degrees/second (rotating mechansim).  Since we don't have a 
        ///                 sensor for this mechanism, it will return -360 for clockwise 
        ///                 rotations and 360 for counter clockwise rotations.
        /// returns:        void
        ///==================================================================================
        void SetSpeed 
        (
            double      speed       /// <I> - target speed degrees/second (rotating mechansim)
        ) override;


        ///==================================================================================
        /// method:         GetCurrentSpeed
        /// description:    Get the current speed of the intake.  The value is in degrees 
        ///                 per second.  Since we don't have a sensor for this mechanism,
        ///                 it will return -360 for clockwise rotations and 360 for 
        ///                 counter clockwise rotations.
        /// returns:        double  speed in degrees/second (rotating mechansim)
        ///==================================================================================
        double GetCurrentSpeed() const override;


        ///==================================================================================
        /// method:         GetTargetSpeecd
        /// description:    Get the target speed of the intake.  The value is in degrees 
        ///                 per second.  Since we don't have a sensor for this mechanism,
        ///                 it will return -360 for clockwise rotations and 360 for 
        ///                 counter clockwise rotations.
        /// returns:        double  speed in degrees/second (rotating mechansim)
        ///==================================================================================
        double GetTargetSpeed() const override; 
        
        
    private:
        IDragonMotorController*     m_motor;
        const double                m_deadbandTol = 0.1;
};




