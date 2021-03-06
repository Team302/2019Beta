
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
#include <subsys/IChassis.h>
#include <subsys/IMechanism.h>
#include <subsys/MechanismControl.h>
#include <subsys/MechanismTypes.h>
#include <controllers/ControlData.h>
#include <subsys/DriveTrainSide.h>

// Third Party Includes

using namespace std;
using namespace frc;

/// @class DragonChassis
/// @brief This is a differential chassis.  Each side of the robot will be treated as a separate mechanism

/// @brief Create the subobjects and initialize the DragonChassis subsystem
DragonChassis::DragonChassis
(
    double 						                            wheelDiameter,		
    double 					    	                        wheelBase,			
    double 						                            track,				
    std::shared_ptr<IDragonMotorController>                 leftMaster,
    std::shared_ptr<IDragonMotorController>                 rightMaster,
    std::vector<std::shared_ptr<IDragonMotorController>>    leftFollowers,
    std::vector<std::shared_ptr<IDragonMotorController>>    rightFollowers
) : m_leftSide( new DriveTrainSide( leftMaster, leftFollowers, wheelDiameter ) ),
    m_rightSide( new DriveTrainSide( rightMaster, rightFollowers, wheelDiameter ) ),
    m_wheelBase( wheelBase ),
    m_wheelTrack( track )
{
}

/// @brief clean up memory when this object gets deleted
DragonChassis::~DragonChassis()
{
    delete m_leftSide;
    delete m_rightSide;
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
    m_leftSide->SetOutput( controlType, leftValue );
    m_rightSide->SetOutput( controlType, rightValue );
}


/// @brief  Return the current position of the center of the DragonChassis in inches.  
/// @return double  position in inches of the center of the chassis
double DragonChassis::GetCurrentPosition() const
{
    return ( m_leftSide->GetCurrentPosition() + m_rightSide->GetCurrentPosition() ) / 2.0;
}

/// @brief  Return the current position of the left side of the DragonChassis in inches.  
/// @return double  position in inches of the left side of the chassis
double DragonChassis::GetCurrentLeftPosition() const
{
    return m_leftSide->GetCurrentPosition();
}

/// @brief  Return the current position of the right side of the DragonChassis in inches.  
/// @return double  position in inches of the right side of the chassis
double DragonChassis::GetCurrentRightPosition() const
{
    return m_rightSide->GetCurrentPosition();
}

/// @brief  Return the target position of the center of the DragonChassis in inches.  
/// @return double  position in inches of the center of the DragonChassis
double DragonChassis::GetTargetPosition() const
{
    return ( m_leftSide->GetTargetPosition() + m_rightSide->GetTargetPosition() ) / 2.0;
}


/// @brief  Return the target position of the left side of the DragonChassis in inches.  
/// @return double  position in inches of the left side of the DragonChassis
double DragonChassis::GetTargetLeftPosition() const
{
    return m_leftSide->GetTargetPosition();
}

/// @brief  Return the target position of the right side of the DragonChassis in inches.  
/// @return double  position in inches of the right side of the DragonChassis
double DragonChassis::GetTargetRightPosition() const
{
    return m_rightSide->GetTargetPosition();
}


/// @brief  Return the current speed of the center of the DragonChassis in inches per second.  
/// @return double  speed in inches per second of the center of the chassis
double DragonChassis::GetCurrentSpeed() const
{
    return ( m_leftSide->GetCurrentSpeed() + m_rightSide->GetCurrentSpeed() ) / 2.0;
}

/// @brief  Return the current speed of the left side of the DragonChassis in inches per second.  
/// @return double  speed in inches per second of the left side of the chassis
double DragonChassis::GetCurrentLeftSpeed() const
{
    return m_leftSide->GetCurrentSpeed();
}

/// @brief  Return the current speed of the right side of the DragonChassis in inches per second.  
/// @return double  speed in inches per second of the right side of the chassis
double DragonChassis::GetCurrentRightSpeed() const
{
    return m_rightSide->GetCurrentSpeed();
}


/// @brief  Get the target speed of the center of the chassis.  The value is in inches per second.
/// @return double	speed in inches/second of the center of the chassis.
double DragonChassis::GetTargetSpeed() const
{
    return ( m_leftSide->GetTargetSpeed() + m_rightSide->GetTargetSpeed() ) / 2.0;
}

/// @brief  Get the target speed of the left side of the chassis.  The value is in inches per second.
/// @return double	speed in inches/second of the left side of the chassis.
double DragonChassis::GetTargetLeftSpeed() const
{
    return m_leftSide->GetTargetSpeed();
}

/// @brief  Get the target speed of the right side of the chassis.  The value is in inches per second.
/// @return double	speed in inches/second of the right side of the chassis.
double DragonChassis::GetTargetRightSpeed() const
{
    return m_rightSide->GetTargetSpeed();
}


/// @brief  Set the control constants (e.g. PIDF values).
/// @param [in] ControlData*   pid - the control constants
/// @return void
void DragonChassis::SetControlConstants
(
    ControlData*                                 pid               
)
{
    m_leftSide->SetControlConstants( pid );
    m_rightSide->SetControlConstants( pid );
}





