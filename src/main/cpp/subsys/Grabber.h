
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

//========================================================================================================
/// Grabber.h
//========================================================================================================
///
/// File Description:
///     This is the Grabber Subsystem
///
//========================================================================================================

// C++ Includes

// FRC includes

// Team 302 includes
#include <hw/IDragonMotorController.h>
#include <subsys/IMechanism.h>
#include <subsys/MechanismControl.h>
#include <subsys/MechanismTypes.h>
#include <controllers/ControlData.h>

// Third Party Includes


//========================================================================================================
///  Class:         IMechanism
///  Description:   Interface for subsystems
//========================================================================================================
class Grabber : public IMechanism
{
    public:

        //==================================================================================
        /// method:         Grabber <<constructor>>
        /// description:    Create the subobjects and initialize the Grabber subsystem
        //==================================================================================
        Grabber();

        //==================================================================================
        /// method:         ~Grabber <<destructor>>
        /// description:    clean up memory when this object gets deleted
        //==================================================================================
        virtual ~Grabber();

        //==================================================================================
        /// method:         GetType
        /// description:    Indicates this is the Grabber
        /// returns:        IMechanism::MECHANISM_TYPE::Grabber
        //==================================================================================
        MechanismTypes::MECHANISM_TYPE GetType() const override;


        //==================================================================================
        /// method:     SetOutput
        /// @brief      Run Grabber as defined 
        /// @param      MechanismControl::MECHANISM_CONTROL_TYPE   controlType:  How are the item(s) being controlled
        /// @param      double                                     value:        Target (units are based on the controlType)
        /// @return     void
        //==================================================================================
        void SetOutput
        (
            MechanismControl::MECHANISM_CONTROL_TYPE controlType,
            double                                   value       
        ) override;


        //==================================================================================
        /// method: GetCurrentPostion
        /// @brief  Return the current position of the Grabber in degrees.  Since we don't have
        ///         a sensor this will return -90 for clockwise rotations and 90 for 
        ///         counter-clockwise rotations.
        /// @return double  position in degrees (rotating mechansim)
        //==================================================================================
        double GetCurrentPosition() const override;


        //==================================================================================
        /// method: GetTargetPostion
        /// @brief  Return the target position of the Grabber in degrees.  Since we don't have
        ///         a sensor this will return -90 for clockwise rotations and 90 for 
        ///         counter-clockwise rotations.
        /// @return double  position in degrees (rotating mechansim)
        //==================================================================================
        double GetTargetPosition() const override;


        //==================================================================================
        /// method: GetCurrentSpeed
        /// @brief  Return the current speed of the Grabber in degrees per second.  Since we 
        ///         don't have a sensor this will return -360 for clockwise rotations and 360 
        ///         for counter-clockwise rotations.
        /// @return double  speed in degrees per second (rotating mechansim)
        //==================================================================================
        double GetCurrentSpeed() const override;


        //==================================================================================
        /// method: GetTargetSpeed
        /// @brief  Return the target speed of the Grabber in degrees per second.  Since we 
        ///         don't have a sensor this will return -360 for clockwise rotations and 360 
        ///         for counter-clockwise rotations.
        /// @return double  speed in degrees per second (rotating mechansim)
        //==================================================================================
        double GetTargetSpeed() const override; 


        //==================================================================================================
        /// method: SetControlConstants
        /// @brief  Set the control constants (e.g. PIDF values).
        /// @param [in] ControlData*   pid - the control constants
        /// @return void
        //==================================================================================================
        void SetControlConstants
        (
            ControlData*        pid                 // <I> - PID control information
        ) override;
        
    private:
        IDragonMotorController*     m_motor;
        const double                m_deadbandTol = 0.1;
};




