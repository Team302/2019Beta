
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
#include <controllers/ControlData.h>

// Third Party Includes

/// @class DriveTrainSide
/// @brief This is the DriveTrainSide sub-mechanism
class DriveTrainSide : public IMechanism
{
    public:

        /// @brief    Create and initialize the DriveTrainSide sub-mechanism
        /// @param [in] std::shared_ptr<IDragonMotorController>   master - master motor for the DriveTrainSide
        /// @param [in] std::vector<std::shared_ptr<IDragonMotorController>>    followers - slave motors for the DriveTrainSide
        /// @param [in] double    wheelSize - diameter of the wheel in inches.
        DriveTrainSide
        (
            std::shared_ptr<IDragonMotorController>                 master,
            std::vector<std::shared_ptr<IDragonMotorController>>    followers,
            double                                                  wheelSize
        );
        DriveTrainSide() = delete;

        /// @brief    clean up memory when this object gets deleted
        virtual ~DriveTrainSide() = default;

        /// @brief  Indicates this is the DriveTrainSide
        /// @return IMechanism::MECHANISM_TYPE::DriveTrainSide
        MechanismTypes::MECHANISM_TYPE GetType() const override;


        /// @brief      Run DriveTrainSide as defined 
        /// @param [in] MechanismControl::MECHANISM_CONTROL_TYPE   controlType:  How are the item(s) being controlled
        /// @param [in] double                                     value:        Target (units are based on the controlType)
        /// @return     void
        void SetOutput
        (
            MechanismControl::MECHANISM_CONTROL_TYPE controlType,
            double                                   value       
        ) override;


        /// @brief  Return the current position of the DriveTrainSide in inches (positive is forward, negative is backward)
        /// @return double  position in inches
        double GetCurrentPosition() const override;


        /// @brief  Return the target position of the DriveTrainSide in inches (positive is forward, negative is backward)
        /// @return double  position in inches
        double GetTargetPosition() const override;


        /// @brief  Return the current speed of the DriveTrainSide in inches / second (positive is forward, negative is backward)
        /// @return double  speed in inches / second
        double GetCurrentSpeed() const override;


        /// @brief  Return the target speed of the DriveTrainSide in inches / second (positive is forward, negative is backward)
        /// @return double  speed in inches / second
        double GetTargetSpeed() const override;


        /// @brief  Set the control constants (e.g. PIDF values).
        /// @param [in] ControlData*   pid - the control constants
        /// @return void
        void SetControlConstants
        (
            ControlData*                                 pid               
        ) override;
        
    private:
        std::shared_ptr<IDragonMotorController>                 m_master;
        std::vector<std::shared_ptr<IDragonMotorController>>    m_slaves;
        double                                                  m_wheelSize;
        double                                                  m_target;

        const double                                            m_deadbandTol = 0.1;
};




