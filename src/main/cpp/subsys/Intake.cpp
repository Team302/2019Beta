
///====================================================================================================================================================
/// Copyright 2019 Lake Orion Robobitcs FIRST Team 302
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

///========================================================================================================
/// Intake.cpp
///========================================================================================================
///
/// File Description:
///     This is the Intake Subsystem
///
///========================================================================================================

// C++ Includes
#include <algorithm>
#include <cmath>
#include <iostream>

// FRC includes

// Team 302 includes
#include <hw/DragonMotorControllerFactory.h>        
#include <hw/IDragonMotorController.h>
#include <subsys/IMechanism.h>
#include <subsys/Intake.h>

// Third Party Includes



///==================================================================================
/// method:         Intake <<constructor>>
/// description:    Create the subobjects and initialize the Intake subsystem
///==================================================================================
Intake::Intake()
{
    // Get the motor controller and set its mode to percent output and stop it
    m_motor = DragonMotorControllerFactory::GetInstance()->GetController( IMechanism::MECHANISM_TYPE::INTAKE, IDragonMotorController::MOTOR_CONTROLLER_TYPE::INTAKE );
    if ( m_motor != nullptr )
    {
        m_motor->SetControlMode( IDragonMotorController::DRAGON_CONTROL_MODE::PERCENT_OUTPUT );
        m_motor->Set( 0.0 );
    }
    else
    {
        std::cout << "==>>Intake::Intake motor not found " << std::endl;
    }
}

///==================================================================================
/// method:         ~Intake <<destructor>>
/// description:    clean up memory when this object gets deleted
///==================================================================================
Intake::~Intake()
{
    // delete owned objects (e.g. delete m_motor;)
}

///==================================================================================
/// method:         GetType
/// description:    Indicates this is the intake
/// returns:        IMechanism::MECHANISM_TYPE::INTAKE
///==================================================================================
IMechanism::MECHANISM_TYPE Intake::GetType() const 
{
    return IMechanism::MECHANISM_TYPE::INTAKE;
}


///==================================================================================
/// method:         SetPercentOutput
/// description:    Run intake in open loop (percent output)
/// returns:        void
///==================================================================================
void Intake::SetPercentOutput
(
    double      value       /// <I> - percent output for the motor(s)
) 
{
    // Make sure value is in range (-1.0 to 1.0) and then set the percent output
    // on the motor (2 calls)
    if ( m_motor != nullptr )
    {
        auto pct = std::min(1.0, std::max(value, -1.0));  // replace std::clamp in c++17
        m_motor->SetControlMode( IDragonMotorController::DRAGON_CONTROL_MODE::PERCENT_OUTPUT );
        m_motor->Set( pct );
    }
}


///==================================================================================
/// method:         SetPosition
/// description:    Run intake in closed loop position mode.  The value is in 
///                 degrees.  Since we don't have a sensor, this will run percent
///                 output in the direction specified.  We will use the standard unit
///                 circle for direction with negative being clockwise and positive
///                 being counter-clockwise.
/// returns:        void
///==================================================================================
void Intake::SetPosition 
(
    double      pos       /// <I> - target position in degrees (rotating mechansim) 
) 
{
    // Since there isn't a sensor, just set the motor speeds based on the position
    // input to either -1.0 or 1.0. Just call the set method with these values.
    double percent = 0.0;
    if ( pos < m_deadbandTol )
    {
        percent = 1.0;
    }
    else if ( pos > m_deadbandTol )
    {
        percent = -1.0;
    }
    SetPercentOutput( percent );
}


///==================================================================================
/// method:         GetCurrentPostion
/// description:    Return the current position of the intake in degrees.  Since
///                 we don't have a sensor this will return -90 for clockwise rotations
///                 and 90 for counter-clockwise rotations.
/// returns:        double  position in degrees (rotating mechansim)
///==================================================================================
double Intake::GetCurrentPosition() const 
{
    // Normally would call GetSelectedSensorPosition, but there is no sensor, so we
    // would call GetMotorOutputPercent.  This isn't currently exposed in our APIs, so 
    // hard code for now 
    return 90.0;
}


///==================================================================================
/// method:         GetTargetPostion
/// description:    Return the target position of the intake.  Since
///                 we don't have a sensor this will return -90 for clockwise rotations
///                 and 90 for counter-clockwise rotations.
/// returns:        double  position in degrees (rotating mechansim)
///==================================================================================
double Intake::GetTargetPosition() const 
{
    // No sensor so it is the same as the current
    return GetCurrentPosition();
}


///==================================================================================
/// method:         SetSpeed
/// description:    Run intake in closed loop velocity mode.  The value is in 
///                 degrees/second (rotating mechansim).  Since we don't have a 
///                 sensor for this mechanism, it will return -360 for clockwise 
///                 rotations and 360 for counter clockwise rotations.
/// returns:        void
///==================================================================================
void Intake::SetSpeed 
(
    double      speed       /// <I> - target speed degrees/second (rotating mechansim)
) 
{
    // Since there isn't a sensor, just set the motor speeds based on the position
    // input to either -1.0 or 1.0. Just call the set method with these values.
    // TODO:: maybe we should run a voltqge control mode instead
    double percent = 0.0;
    if ( speed < m_deadbandTol )
    {
        percent = 1.0;
    }
    else if ( speed > m_deadbandTol )
    {
        percent = -1.0;
    }
    SetPercentOutput( percent );
}


///==================================================================================
/// method:         GetCurrentSpeed
/// description:    Get the current speed of the intake.  The value is in degrees 
///                 per second.  Since we don't have a sensor for this mechanism,
///                 it will return -360 for clockwise rotations and 360 for 
///                 counter clockwise rotations.
/// returns:        double  speed in degrees/second (rotating mechansim)
///==================================================================================
double Intake::GetCurrentSpeed() const 
{
    // Normally would call GetSelectedSensorVelocity, but there is no sensor, so we
    // would call GetMotorOutputPercent.  This isn't currently exposed in our APIs, so 
    // hard code for now 
    return 360.0;
}


///==================================================================================
/// method:         GetTargetSpeecd
/// description:    Get the target speed of the intake.  The value is in degrees 
///                 per second.  Since we don't have a sensor for this mechanism,
///                 it will return -360 for clockwise rotations and 360 for 
///                 counter clockwise rotations.
/// returns:        double  speed in degrees/second (rotating mechansim)
///==================================================================================
double Intake::GetTargetSpeed() const 
{
    // No sensor so it is the same as the current
    return GetCurrentPosition();
}





