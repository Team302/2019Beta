
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

// FRC includes

// Team 302 includes
#include <subsys/IMechanism.h>
#include <subsys/MechanismControl.h>
#include <subsys/MechanismTypes.h>
#include <controllers/ControlData.h>
// Third Party Includes


///	 @interface IChassis
///  @brief	    Interface for differential drives
class IChassis
{
	public:

        /// @brief      Run chassis 
        /// @param [in] MechanismControl::MECHANISM_CONTROL_TYPE   controlType:  How are the item(s) being controlled
        /// @param [in] double                                     leftVvalue:   Left side target (units are based on the controlType)
        /// @param [in] double                                     rightValue:   Right side target (units are based on the controlType)
        /// @return     void
        virtual void SetOutput
        (
            MechanismControl::MECHANISM_CONTROL_TYPE controlType,
            double                                   leftValue,
            double                                   rightValue     
        ) = 0;


        /// @brief  Return the current position of the center of the DragonChassis in inches.  
        /// @return double  position in inches of the center of the chassis
        virtual double GetCurrentPosition() const = 0;

        /// @brief  Return the current position of the left side of the DragonChassis in inches.  
        /// @return double  position in inches of the left side of the chassis
        virtual double GetCurrentLeftPosition() const = 0;

        /// @brief  Return the current position of the right side of the DragonChassis in inches.  
        /// @return double  position in inches of the right side of the chassis
        virtual double GetCurrentRightPosition() const = 0;

        /// @brief  Return the target position of the center of the DragonChassis in inches.  
        /// @return double  position in inches of the center of the DragonChassis
        virtual double GetTargetPosition() const = 0;

        /// @brief  Return the target position of the left side of the DragonChassis in inches.  
        /// @return double  position in inches of the left side of the DragonChassis
        virtual double GetTargetLeftPosition() const = 0;

        /// @brief  Return the target position of the right side of the DragonChassis in inches.  
        /// @return double  position in inches of the right side of the DragonChassis
        virtual double GetTargetRightPosition() const = 0;

        /// @brief  Return the current speed of the center of the DragonChassis in inches per second.  
        /// @return double  speed in inches per second of the center of the chassis
        virtual double GetCurrentSpeed() const = 0;

        /// @brief  Return the current speed of the left side of the DragonChassis in inches per second.  
        /// @return double  speed in inches per second of the left side of the chassis
        virtual double GetCurrentLeftSpeed() const = 0;

        /// @brief  Return the current speed of the right side of the DragonChassis in inches per second.  
        /// @return double  speed in inches per second of the right side of the chassis
        virtual double GetCurrentRightSpeed() const = 0;


        /// @brief  Get the target speed of the center of the chassis.  The value is in inches per second.
        /// @return double	speed in inches/second of the center of the chassis.
        virtual double GetTargetSpeed() const = 0;

        /// @brief  Get the target speed of the left side of the chassis.  The value is in inches per second.
        /// @return double	speed in inches/second of the left side of the chassis.
        virtual double GetTargetLeftSpeed() const = 0;

        /// @brief  Get the target speed of the right side of the chassis.  The value is in inches per second.
        /// @return double	speed in inches/second of the right side of the chassis.
        virtual double GetTargetRightSpeed() const = 0;


        /// @brief  Set the control constants (e.g. PIDF values).
        /// @param [in] ControlData*                                   pid:  the control constants
        /// @return void
        virtual void SetControlConstants
        (
            ControlData*                                pid                 
        ) = 0;


	IChassis() = default;
	virtual ~IChassis() = default;
};



