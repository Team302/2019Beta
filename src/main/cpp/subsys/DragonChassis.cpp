
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


// C++ Includes
#include <memory>

// FRC includes

// Team 302 includes
#include <subsys/DragonChassis.h>
#include <hw/interfaces/IDragonMotorController.h>
#include <subsys/IDifferntialChassis.h>
#include <subsys/IMechanism.h>
#include <subsys/MechanismControl.h>
#include <subsys/MechanismTypes.h>
#include <xmlcontrol/PIDData.h>

// Third Party Includes

using namespace std;
using namespace frc;

/// @class DragonChassis
/// @brief This is a differential chassis.  Each side of the robot will be treated as a separate mechanism

/// @brief Create the subobjects and initialize the DragonChassis subsystem
DragonChassis::DragonChassis()
{

}

/// @brief clean up memory when this object gets deleted
DragonChassis::~DragonChassis()
{

}

/// @brief  Get the left side of the chassis
/// @return std::shared_ptr<IMechanism> left side, so mechanism calls can be utilized
shared_ptr<IMechanism> DragonChassis::GetLeftSide() const
{
    shared_ptr<IMechanism> left = nullptr;
    return left;
}

/// @brief  Get the right side of the chassis
/// @return std::shared_ptr<IMechanism> right side, so mechanism calls can be utilized
shared_ptr<IMechanism> DragonChassis::GetRightSide() const
{
    shared_ptr<IMechanism> right = nullptr;
    return right;
}


/// @brief      Run chassis 
/// @param [in] MechanismControl::MECHANISM_CONTROL_TYPE   controlType:  How are the item(s) being controlled
/// @param [in] double                                     leftVvalue:   Left side target (units are based on the controlType)
/// @param [in] double                                     rightValue:   Right side target (units are based on the controlType)
/// @return     void
void DragonChassis::SetOutput
(
    MechanismControl::MECHANISM_CONTROL_TYPE controlType,
    double                                   leftValue,
    double                                   rightValue     
)
{

}


/// @brief  Return the current position of the center of the DragonChassis in inches.  
/// @return double  position in inches of the center of the chassis
double DragonChassis::GetCurrentPosition() const
{
    double pos = 0.0;
    return pos;
}

/// @brief  Return the current position of the left side of the DragonChassis in inches.  
/// @return double  position in inches of the left side of the chassis
double DragonChassis::GetCurrentLeftPosition() const
{
    double pos = 0.0;
    return pos;
}

/// @brief  Return the current position of the right side of the DragonChassis in inches.  
/// @return double  position in inches of the right side of the chassis
double DragonChassis::GetCurrentRightPosition() const
{
    double pos = 0.0;
    return pos;
}

/// @brief  Return the target position of the center of the DragonChassis in inches.  
/// @return double  position in inches of the center of the DragonChassis
double DragonChassis::GetTargetPosition() const
{
    double pos = 0.0;
    return pos;
}


/// @brief  Return the target position of the left side of the DragonChassis in inches.  
/// @return double  position in inches of the left side of the DragonChassis
double DragonChassis::GetTargetLeftPosition() const
{
    double pos = 0.0;
    return pos;
}

/// @brief  Return the target position of the right side of the DragonChassis in inches.  
/// @return double  position in inches of the right side of the DragonChassis
double DragonChassis::GetTargetRightPosition() const
{
    double pos = 0.0;
    return pos;
}


/// @brief  Return the current speed of the center of the DragonChassis in inches per second.  
/// @return double  speed in inches per second of the center of the chassis
double DragonChassis::GetCurrentSpeed() const
{
    double speed = 0.0;
    return speed;
}

/// @brief  Return the current speed of the left side of the DragonChassis in inches per second.  
/// @return double  speed in inches per second of the left side of the chassis
double DragonChassis::GetCurrentLeftSpeed() const
{
    double speed = 0.0;
    return speed;
}

/// @brief  Return the current speed of the right side of the DragonChassis in inches per second.  
/// @return double  speed in inches per second of the right side of the chassis
double DragonChassis::GetCurrentRightSpeed() const
{
    double speed = 0.0;
    return speed;
}


/// @brief  Get the target speed of the center of the chassis.  The value is in inches per second.
/// @return double	speed in inches/second of the center of the chassis.
double DragonChassis::GetTargetSpeed() const
{
    double speed = 0.0;
    return speed;
}

/// @brief  Get the target speed of the left side of the chassis.  The value is in inches per second.
/// @return double	speed in inches/second of the left side of the chassis.
double DragonChassis::GetTargetLeftSpeed() const
{
    double speed = 0.0;
    return speed;
}

/// @brief  Get the target speed of the right side of the chassis.  The value is in inches per second.
/// @return double	speed in inches/second of the right side of the chassis.
double DragonChassis::GetTargetRightSpeed() const
{
    double speed = 0.0;
    return speed;
}


/// @brief  Set the control constants (e.g. PIDF values).
/// @param [in] PIDData*   pid - the control constants
/// @return void
void DragonChassis::SetControlConstants
(
    PIDData*                                 pid               
)
{

}





