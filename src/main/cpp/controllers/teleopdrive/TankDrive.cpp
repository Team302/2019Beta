
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

// C++ Includes
#include <memory>

// FRC includes

// Team 302 Includes
#include <controllers/teleopdrive/TankDrive.h>
#include <gamepad/TeleopControl.h>
#include <subsys/IChassis.h>
#include <subsys/ChassisFactory.h>
#include <subsys/MechanismControl.h>
#include <utils/Logger.h>

using namespace std;

/// @class TankDrive
/// @brief Drive differential chassis with one joystick controlling each side of the robot

/// @brief initialize the object 
TankDrive::TankDrive() : ITeleopDrive(),
                         m_chassis( ChassisFactory::GetChassisFactory()->GetIChassis() ),
                         m_controller( TeleopControl::GetInstance() )
{
    if ( m_controller != nullptr  )
    {
        m_controller->SetAxisProfile( TeleopControl::FUNCTION_IDENTIFIER::TANK_DRIVE_LEFT_CONTROL, IDragonGamePad::AXIS_PROFILE::CUBED );
        m_controller->SetAxisProfile( TeleopControl::FUNCTION_IDENTIFIER::TANK_DRIVE_RIGHT_CONTROL, IDragonGamePad::AXIS_PROFILE::CUBED );
    }
    else
    {
        Logger::GetLogger()->LogError( string( "TankDrive::TankDrive"), string("TelopControl is nullptr"));
    }

    if ( m_chassis.get() == nullptr )
    {
        Logger::GetLogger()->LogError( string( "TankDrive::TankDrive"), string("Chassis is nullptr"));
    }
}

/// @brief  Read two joysticks and drive a differential chassis (each joystick drives a separate side)
/// @return void
void TankDrive::Drive()
{
    auto left = m_controller->GetAxisValue( TeleopControl::FUNCTION_IDENTIFIER::TANK_DRIVE_LEFT_CONTROL );
    auto right = m_controller->GetAxisValue( TeleopControl::FUNCTION_IDENTIFIER::TANK_DRIVE_RIGHT_CONTROL );

    m_chassis.get()->SetOutput( MechanismControl::PERCENT_OUTPUT, left, right );
}
