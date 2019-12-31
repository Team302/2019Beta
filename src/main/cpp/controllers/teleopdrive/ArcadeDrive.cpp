
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
#include <controllers/teleopdrive/ArcadeDrive.h>
#include <gamepad/DragonXBox.h>
#include <subsys/IChassis.h>

using namespace std;

ArcadeDrive::ArcadeDrive
(
    shared_ptr<IChassis>    chassis,
    shared_ptr<DragonXBox>  xbox
) : ThrottleSteerDrive( chassis, xbox )
{
    xbox->SetAxisProfile( IDragonGamePad::AXIS_IDENTIFIER::LEFT_JOYSTICK_Y, IDragonGamePad::AXIS_PROFILE::CUBED );
    xbox->SetAxisProfile( IDragonGamePad::AXIS_IDENTIFIER::RIGHT_JOYSTICK_X, IDragonGamePad::AXIS_PROFILE::CUBED );
}

//=======================================================================
double ArcadeDrive::GetThrottle()
{
    auto xbox = GetXBox();
    return ( ( xbox != nullptr ) ? xbox->GetAxisValue( IDragonGamePad::AXIS_IDENTIFIER::LEFT_JOYSTICK_Y) : 0.0 );
}

//=======================================================================
double ArcadeDrive::GetSteer()
{
    auto xbox = GetXBox();
    return ( ( xbox != nullptr ) ? xbox->GetAxisValue( IDragonGamePad::AXIS_IDENTIFIER::RIGHT_JOYSTICK_X) : 0.0 );
}


