
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

/// @class DriveTrainSide
/// @brief This is the DriveTrainSide Subsystem

// C++ Includes
#include <algorithm>
#define _USE_MATH_DEFINES // for C++  with cmath 
#include <cmath>
#include <iostream>

// FRC includes

// Team 302 includes
#include <hw/factories/DragonMotorControllerFactory.h>        
#include <hw/interfaces/IDragonMotorController.h>
#include <subsys/IMechanism.h>
#include <subsys/DriveTrainSide.h>
#include <subsys/MechanismControl.h>
#include <subsys/MechanismTypes.h>
#include <utils/Logger.h>

// Third Party Includes

using namespace std;

/// @brief    Create and initialize the DriveTrainSide sub-mechanism
/// @param [in] std::shared_ptr<IDragonMotorController>   master - master motor for the DriveTrainSide
/// @param [in] std::vector<std::shared_ptr<IDragonMotorController>>    followers - slave motors for the DriveTrainSide
/// @param [in] double    wheelSize - diameter of the wheel in inches.
DriveTrainSide::DriveTrainSide
(
    shared_ptr<IDragonMotorController>                      master,
    vector<shared_ptr<IDragonMotorController>>              followers,
    double                                                  wheelSize
) : m_master( master ),
    m_slaves( move( followers ) ), 
    m_wheelSize( wheelSize ),
    m_target( 0.0 )
{
    if ( m_master.get() == nullptr ) 
    {
        Logger::GetLogger()->LogError( string( "DriveTrainSide constructor" ), string( "master is nullptr" ) );
    }
}

/// @brief  Indicates this is the DriveTrainSide
/// @return IMechanism::MECHANISM_TYPE::DriveTrainSide
MechanismTypes::MECHANISM_TYPE DriveTrainSide::GetType() const 
{
    return MechanismTypes::MECHANISM_TYPE::DRIVETRAIN_SIDE;
}



/// @brief      Run DriveTrainSide as defined 
/// @param [in] MechanismControl::MECHANISM_CONTROL_TYPE   controlType:  How are the item(s) being controlled
/// @param [in] double                                     value:        Target (units are based on the controlType)
/// @return     void
void DriveTrainSide::SetOutput
(
    MechanismControl::MECHANISM_CONTROL_TYPE controlType,
    double                                   value       
) 
{
    m_target = value;
    if ( m_master != nullptr )
    {
        // todo map mechanism control mode to motor control mode (create method)
        m_master->SetControlMode( IDragonMotorController::DRAGON_CONTROL_MODE::PERCENT_OUTPUT );
        m_master->Set( value );
    }
    else
    {
        Logger::GetLogger()->LogError( "DriveTrainSide::SetOutput", "No master" );
    }
}


/// @brief  Return the current position of the DriveTrainSide in inches.  
/// @return double  position in inches (positive is forward, negative is backward)
double DriveTrainSide::GetCurrentPosition() const
{
    double distance = 0.0;
    if ( m_master != nullptr )
    {
        distance = ( m_wheelSize * M_PI );          // distance the wheel travels per revolution
        auto nRotations = m_master->GetRotations(); // number of rotations
        distance *= nRotations;                     // distance per revolution * number of revolutions is the distance
    }
    else
    {
        Logger::GetLogger()->LogError( "DriveTrainSide::SetOutput", "No master" );
    }
    return distance;
}


/// @brief  Return the target position of the DriveTrainSide in inches.  
double DriveTrainSide::GetTargetPosition() const
{
    return m_target;  // todo either need 2 variables or know the current mode
}

/// @brief  Return the current speed of the DriveTrainSide in degrees per second.  Since we 
///         don't have a sensor this will return -360 for clockwise rotations and 360 
///         for counter-clockwise rotations.
/// @return double  speed in degrees per second (rotating mechansim)
double DriveTrainSide::GetCurrentSpeed() const
{
    double speed = 0.0;
    if ( m_master != nullptr )
    {
        speed = ( m_wheelSize * M_PI ); // distance the wheel travels per revolution (inches)
        auto rps = m_master->GetRPS();  // number of rotations per second
        speed *= rps;                   // distance per revolution * revolutions per second is inches per second
    }
    else
    {
        Logger::GetLogger()->LogError( "DriveTrainSide::SetOutput", "No master" );
    }
    return speed;

}


/// @brief  Return the target speed of the DriveTrainSide in degrees per second.  Since we 
///         don't have a sensor this will return -360 for clockwise rotations and 360 
///         for counter-clockwise rotations.
/// @return double  speed in degrees per second (rotating mechansim)
double DriveTrainSide::GetTargetSpeed() const
{
    return m_target;  // todo either need 2 variables or know the current mode
}



/// @brief  Set the control constants (e.g. PIDF values).
/// @param [in] ControlData*   pid - the control constants
/// @return void
void DriveTrainSide::SetControlConstants
(
    ControlData*                                 pid                 
)
{
    // todo:  need to account for voltage mode
    // NO-OP since we can't run closed loop since we don't have sensors
}




