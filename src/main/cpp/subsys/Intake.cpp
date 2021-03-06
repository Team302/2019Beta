
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

/// @class Intake
/// @brief This is the Intake Subsystem

// C++ Includes
#include <algorithm>
#include <cmath>
#include <iostream>

// FRC includes

// Team 302 includes
#include <hw/factories/DragonMotorControllerFactory.h>        
#include <hw/interfaces/IDragonMotorController.h>
#include <subsys/IMechanism.h>
#include <subsys/Intake.h>
#include <subsys/MechanismControl.h>
#include <subsys/MechanismTypes.h>
#include <utils/Logger.h>

// Third Party Includes

using namespace std;

/// @brief    Create the subobjects and initialize the Intake subsystem
/// @param    std::shared_ptr<IDragonMotorController>  intake motor controller
Intake::Intake
(
    shared_ptr<IDragonMotorController>              motor
) : m_motor ( motor )
{
    if ( m_motor.get() == nullptr ) 
    {
        Logger::GetLogger()->LogError( string( "Intake constructor" ), string( "motor is nullptr" ) );
    }
}

/// @brief  Indicates this is the intake
/// @return IMechanism::MECHANISM_TYPE::INTAKE
MechanismTypes::MECHANISM_TYPE Intake::GetType() const 
{
    return MechanismTypes::MECHANISM_TYPE::INTAKE;
}



/// @brief      Run intake as defined 
/// @param [in] MechanismControl::MECHANISM_CONTROL_TYPE   controlType:  How are the item(s) being controlled
/// @param [in] double                                     value:        Target (units are based on the controlType)
/// @return     void
void Intake::SetOutput
(
    MechanismControl::MECHANISM_CONTROL_TYPE controlType,
    double                                   value       
) 
{
    if ( controlType != MechanismControl::MECHANISM_CONTROL_TYPE::PERCENT_OUTPUT )
    {
        Logger::GetLogger()->LogError( "Intake::SetOutput", "invalid Control type option" );
    }

    // Make sure value is in range (-1.0 to 1.0) and then set the percent output
    // on the motor (2 calls)
    if ( m_motor != nullptr )
    {
        auto pct = clamp( value, -1.0, 1.0 );
        m_motor->SetControlMode( IDragonMotorController::DRAGON_CONTROL_MODE::PERCENT_OUTPUT );
        m_motor->Set( pct );
    }
    else
    {
        Logger::GetLogger()->LogError( "Intake::SetOutput", "No motors" );
    }
}


/// @brief  Return the current position of the intake in degrees.  Since we don't have
///         a sensor this will return -90 for clockwise rotations and 90 for 
///         counter-clockwise rotations.
/// @param [in] MechanismControl::MECHANISM_CONTROL_ID     controlItems: What item(s) are being requested
/// @return double  position in degrees (rotating mechansim)
double Intake::GetCurrentPosition() const
{
    // Normally would call GetSelectedSensorPosition, but there is no sensor, so we
    // would call GetMotorOutputPercent.  This isn't currently exposed in our APIs, so 
    // hard code for now 
    return 90.0;
}


/// @brief  Return the target position of the intake in degrees.  Since we don't have
///         a sensor this will return -90 for clockwise rotations and 90 for 
///         counter-clockwise rotations.
/// @return double  position in degrees (rotating mechansim)
double Intake::GetTargetPosition() const
{
    // No sensor so it is the same as the current
    return GetCurrentPosition();
}

/// @brief  Return the current speed of the intake in degrees per second.  Since we 
///         don't have a sensor this will return -360 for clockwise rotations and 360 
///         for counter-clockwise rotations.
/// @return double  speed in degrees per second (rotating mechansim)
double Intake::GetCurrentSpeed() const
{
    // Normally would call GetSelectedSensorVelocity, but there is no sensor, so we
    // would call GetMotorOutputPercent.  This isn't currently exposed in our APIs, so 
    // hard code for now 
    return 360.0;
}


/// @brief  Return the target speed of the intake in degrees per second.  Since we 
///         don't have a sensor this will return -360 for clockwise rotations and 360 
///         for counter-clockwise rotations.
/// @return double  speed in degrees per second (rotating mechansim)
double Intake::GetTargetSpeed() const
{
    // No sensor so it is the same as the current
    return GetCurrentPosition();
}



/// @brief  Set the control constants (e.g. PIDF values).
/// @param [in] ControlData*   pid - the control constants
/// @return void
void Intake::SetControlConstants
(
    ControlData*                                 pid                 
)
{
    // todo:  need to account for voltage mode
    // NO-OP since we can't run closed loop since we don't have sensors
}




