
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

//========================================================================================================
/// @interface IMechanism
/// @brief     This is the interface for all subsystems
//========================================================================================================

// C++ Includes
#include <vector>

// FRC includes

// Team 302 includes
#include <subsys/MechanismControl.h>
#include <subsys/MechanismTypes.h>
#include <xmlcontrol/PIDData.h>
// Third Party Includes


//========================================================================================================
///	 @interface IMechanism
///  @brief	    Interface for subsystems
//========================================================================================================
class IMechanism
{
	public:

        //==================================================================================
        /// method:         GetType
        /// @brief          Indicates the type of mechanism this is
        /// @return         MechanismTypes::MECHANISM_TYPE
        //==================================================================================
        virtual MechanismTypes::MECHANISM_TYPE GetType() const = 0;


        //==================================================================================
        /// method:     SetOutput
        /// @brief      Run mechanism as defined 
        /// @param [in] MechanismControl::MECHANISM_CONTROL_TYPE   controlType:  How are the item(s) being controlled
        /// @param [in] double                                     value:        Target (units are based on the controlType)
        /// @return     void
        //==================================================================================
        virtual void SetOutput
        (
            MechanismControl::MECHANISM_CONTROL_TYPE controlType,
            double                                   value       
        ) = 0;


        //==================================================================================================
        /// method: GetCurrentPostion
        /// @brief  Return the current position of the mechanism.  The value is in inches or degrees.
        /// @return double	position in inches (translating mechanisms) or degrees (rotating mechanisms)
        //==================================================================================================
        virtual double GetCurrentPosition() const = 0;

        //==================================================================================================
        /// method: GetTargetPostion
        /// @brief  Return the targget position of the mechanism.  The value is in inches or degrees.
        /// @return double	position in inches (translating mechanisms) or degrees (rotating mechanisms)
        //==================================================================================================
        virtual double GetTargetPosition() const = 0;

        //==================================================================================================
        /// method: GetCurrentSpeed
        /// @brief  Get the current speed of the mechanism.  The value is in inches per second or degrees per second.
        /// @return double	speed in inches/second (translating mechanisms) or degrees/second (rotating mechanisms)
        //==================================================================================================
        virtual double GetCurrentSpeed() const =0;


        //==================================================================================================
        /// method: GetTargetSpeed
        /// @brief  Get the target speed of the mechanism.  The value is in inches per second or degrees per second.
        /// @param [in] MechanismControl::MECHANISM_CONTROL_ID     controlItems: What item(s) are being requested
        /// @return double	speed in inches/second (translating mechanisms) or degrees/second (rotating mechanisms)
        //==================================================================================================
        virtual double GetTargetSpeed() const = 0;


        //==================================================================================================
        /// method: SetControlConstants
        /// @brief  Set the control constants (e.g. PIDF values).
        /// @param [in] PIDData*                                   pid:  the control constants
        /// @return void
        //==================================================================================================
        virtual void SetControlConstants
        (
            PIDData*                                pid                 
        ) = 0;


	IMechanism() = default;
	virtual ~IMechanism() = default;
};
typedef std::vector<IMechanism*> IMechanismVector;



