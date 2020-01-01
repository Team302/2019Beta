
//====================================================================================================================================================
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
//====================================================================================================================================================

#pragma once

// C++ Includes
#include <memory>

// FRC includes

// Team 302 includes
#include <hw/interfaces/IDragonMotorController.h>
#include <subsys/IMechanism.h>
#include <subsys/MechanismControl.h>
#include <subsys/MechanismTypes.h>
#include <xmlcontrol/ControlData.h>

// Third Party Includes

/// @class Intake
/// @brief This is the Intake Subsystem
class Intake : public IMechanism
{
    public:

        /// @brief    Create and initialize the Intake subsystem
        /// @param    std::shared_ptr<IDragonMotorController>   motor - drive motor for the intake
        Intake
        (
            std::shared_ptr<IDragonMotorController>     motor
        );
        Intake() = delete;

        /// @brief    clean up memory when this object gets deleted
        virtual ~Intake() = default;

        /// @brief  Indicates this is the intake
        /// @return IMechanism::MECHANISM_TYPE::INTAKE
        MechanismTypes::MECHANISM_TYPE GetType() const override;


        /// @brief      Run intake as defined 
        /// @param [in] MechanismControl::MECHANISM_CONTROL_TYPE   controlType:  How are the item(s) being controlled
        /// @param [in] double                                     value:        Target (units are based on the controlType)
        /// @return     void
        void SetOutput
        (
            MechanismControl::MECHANISM_CONTROL_TYPE controlType,
            double                                   value       
        ) override;


        /// @brief  Return the current position of the intake in degrees.  Since we don't have
        ///         a sensor this will return -90 for clockwise rotations and 90 for 
        ///         counter-clockwise rotations.
        /// @return double  position in degrees (rotating mechansim)
        double GetCurrentPosition() const override;


        /// @brief  Return the target position of the intake in degrees.  Since we don't have
        ///         a sensor this will return -90 for clockwise rotations and 90 for 
        ///         counter-clockwise rotations.
        /// @return double  position in degrees (rotating mechansim)
        double GetTargetPosition() const override;


        /// @brief  Return the current speed of the intake in degrees per second.  Since we 
        ///         don't have a sensor this will return -360 for clockwise rotations and 360 
        ///         for counter-clockwise rotations.
        /// @return double  speed in degrees per second (rotating mechansim)
        double GetCurrentSpeed() const override;


        /// @brief  Return the target speed of the intake in degrees per second.  Since we 
        ///         don't have a sensor this will return -360 for clockwise rotations and 360 
        ///         for counter-clockwise rotations.
        /// @return double  speed in degrees per second (rotating mechansim)
        double GetTargetSpeed() const override;


        /// @brief  Set the control constants (e.g. PIDF values).
        /// @param [in] ControlData*   pid - the control constants
        /// @return void
        void SetControlConstants
        (
            ControlData*                                 pid               
        ) override;
        
    private:
        std::shared_ptr<IDragonMotorController>     m_motor;
        const double                                m_deadbandTol = 0.1;
};




