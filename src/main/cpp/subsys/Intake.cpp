
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

//========================================================================================================
/// @class Intake
/// @brief This is the Intake Subsystem
//========================================================================================================

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

//==================================================================================
/// method:         Intake <<constructor>>
/// @brief    Create the subobjects and initialize the Intake subsystem
//==================================================================================
Intake::Intake()
{
    // Get the motor controller and set its mode to percent output and stop it
    /**
    m_motor = DragonMotorControllerFactory::GetInstance()->GetController( IMechanism::MECHANISM_TYPE::INTAKE, MOTOR_CONTROLLER_USAGE::INTAKE );
    if ( m_motor != nullptr )
    {
        m_motor->SetControlMode( IDragonMotorController::DRAGON_CONTROL_MODE::PERCENT_OUTPUT );
        m_motor->Set( 0.0 );
    }
    else
    {
        std::cout << "==>>Intake::Intake motor not found " << std::endl;
    }
    **/
}

//==================================================================================
/// method:         ~Intake <<destructor>>
/// @brief    clean up memory when this object gets deleted
//==================================================================================
Intake::~Intake()
{
    // delete owned objects (e.g. delete m_motor;)
}

//==================================================================================
/// method: GetType
/// @brief  Indicates this is the intake
/// @return IMechanism::MECHANISM_TYPE::INTAKE
//==================================================================================
MechanismTypes::MECHANISM_TYPE Intake::GetType() const 
{
    return MechanismTypes::MECHANISM_TYPE::INTAKE;
}


//==================================================================================
/// method: SetOutput
/// @brief      Run intake as defined 
/// @param [in] MechanismControl::MECHANISM_CONTROL_ID     controlItems: What item(s) are being controlled
/// @param [in] MechanismControl::MECHANISM_CONTROL_TYPE   controlType:  How are the item(s) being controlled
/// @param [in] double                                     value:        Target (units are based on the controlType)
/// @return     void
//==================================================================================
void Intake::SetOutput
(
    MechanismControl::MECHANISM_CONTROL_ID   controlItems,
    MechanismControl::MECHANISM_CONTROL_TYPE controlType,
    double                                   value       
) 
{
    if ( controlItems != MechanismControl::ALL_MOTORS )
    {
        Logger::GetLogger()->LogError( "Intake::SetOutput", "invalid Control Items option" );
    }

    if ( controlType != MechanismControl::MECHANISM_CONTROL_TYPE::PERCENT_OUTPUT )
    {
        Logger::GetLogger()->LogError( "Intake::SetOutput", "invalid Control type option" );
    }

    // Make sure value is in range (-1.0 to 1.0) and then set the percent output
    // on the motor (2 calls)
    if ( m_motor != nullptr )
    {
        auto pct = min(1.0, max(value, -1.0));  // replace std::clamp in c++17
        m_motor->SetControlMode( IDragonMotorController::DRAGON_CONTROL_MODE::PERCENT_OUTPUT );
        m_motor->Set( pct );
    }
    else
    {
        Logger::GetLogger()->LogError( "Intake::SetOutput", "No motors" );
    }
}


//==================================================================================
/// method: GetCurrentPostion
/// @brief  Return the current position of the intake in degrees.  Since we don't have
///         a sensor this will return -90 for clockwise rotations and 90 for 
///         counter-clockwise rotations.
/// @param [in] MechanismControl::MECHANISM_CONTROL_ID     controlItems: What item(s) are being requested
/// @return double  position in degrees (rotating mechansim)
//==================================================================================
double Intake::GetCurrentPosition
(
    MechanismControl::MECHANISM_CONTROL_ID   controlItems
) const
{
    // validate the request
    if ( controlItems != MechanismControl::ALL_MOTORS )
    {
        Logger::GetLogger()->LogError( "Intake::SetOutput", "invalid Control Items option" );
    }

    // Normally would call GetSelectedSensorPosition, but there is no sensor, so we
    // would call GetMotorOutputPercent.  This isn't currently exposed in our APIs, so 
    // hard code for now 
    return 90.0;
}


//==================================================================================
/// method: GetTargetPostion
/// @brief  Return the target position of the intake in degrees.  Since we don't have
///         a sensor this will return -90 for clockwise rotations and 90 for 
///         counter-clockwise rotations.
/// @param [in] MechanismControl::MECHANISM_CONTROL_ID     controlItems: What item(s) are being requested
/// @return double  position in degrees (rotating mechansim)
//==================================================================================
double Intake::GetTargetPosition
(
    MechanismControl::MECHANISM_CONTROL_ID   controlItems
) const
{
    // validate the request
    if ( controlItems != MechanismControl::ALL_MOTORS )
    {
        Logger::GetLogger()->LogError( "Intake::SetOutput", "invalid Control Items option" );
    }

    // No sensor so it is the same as the current
    return GetCurrentPosition( controlItems );
}

//==================================================================================
/// method: GetCurrentSpeed
/// @brief  Return the current speed of the intake in degrees per second.  Since we 
///         don't have a sensor this will return -360 for clockwise rotations and 360 
///         for counter-clockwise rotations.
/// @param [in] MechanismControl::MECHANISM_CONTROL_ID     controlItems: What item(s) are being requested
/// @return double  speed in degrees per second (rotating mechansim)
//==================================================================================
double Intake::GetCurrentSpeed
(
    MechanismControl::MECHANISM_CONTROL_ID   controlItems
) const
{
    // validate the request
    if ( controlItems != MechanismControl::ALL_MOTORS )
    {
        Logger::GetLogger()->LogError( "Intake::SetOutput", "invalid Control Items option" );
    }

    // Normally would call GetSelectedSensorVelocity, but there is no sensor, so we
    // would call GetMotorOutputPercent.  This isn't currently exposed in our APIs, so 
    // hard code for now 
    return 360.0;
}


//==================================================================================
/// method: GetTargetSpeecd
/// @brief  Return the target speed of the intake in degrees per second.  Since we 
///         don't have a sensor this will return -360 for clockwise rotations and 360 
///         for counter-clockwise rotations.
/// @param [in] MechanismControl::MECHANISM_CONTROL_ID     controlItems: What item(s) are being requested
/// @return double  speed in degrees per second (rotating mechansim)
//==================================================================================
double Intake::GetTargetSpeed
(
    MechanismControl::MECHANISM_CONTROL_ID   controlItems
) const
{
    // validate the request
    if ( controlItems != MechanismControl::ALL_MOTORS )
    {
        Logger::GetLogger()->LogError( "Intake::SetOutput", "invalid Control Items option" );
    }

    // No sensor so it is the same as the current
    return GetCurrentPosition( controlItems );
}



//==================================================================================================
/// method: SetControlConstants
/// @brief  Set the control constants (e.g. PIDF values).
/// @param [in] MechanismControl::MECHANISM_CONTROL_ID     controlItems: What item(s) are being controlled
/// @param [in] PIDData*   pid - the control constants
/// @return void
//==================================================================================================
void Intake::SetControlConstants
(
    MechanismControl::MECHANISM_CONTROL_ID   controlItems,
    PIDData*                                 pid                 
)
{
    // validate the request
    if ( controlItems != MechanismControl::ALL_MOTORS )
    {
        Logger::GetLogger()->LogError( "Intake::SetControlConstants", "invalid Control Items option" );
    }

    // todo:  need to account for voltage mode
    // NO-OP since we can't run closed loop since we don't have sensors
}




