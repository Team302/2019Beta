
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
#include <controllers/teleopdrive/GTADrive.h>
#include <gamepad/DragonXBox.h>
#include <subsys/IChassis.h>

using namespace std;

GTADrive::GTADrive
(
    shared_ptr<IChassis>    chassis,
    shared_ptr<DragonXBox>  xbox
) : ThrottleSteerDrive( chassis, xbox )
{
    if ( xbox != nullptr )
    {
        xbox->SetAxisProfile( IDragonGamePad::AXIS_IDENTIFIER::LEFT_TRIGGER, IDragonGamePad::AXIS_PROFILE::CUBED );
        xbox->SetAxisProfile( IDragonGamePad::AXIS_IDENTIFIER::RIGHT_TRIGGER, IDragonGamePad::AXIS_PROFILE::CUBED );
        xbox->SetAxisProfile( IDragonGamePad::AXIS_IDENTIFIER::LEFT_JOYSTICK_X, IDragonGamePad::AXIS_PROFILE::CUBED );
    }
}

//=======================================================================
double GTADrive::GetThrottle()
{
    auto xbox = GetXBox();
    double leftTrigger = 0.0;
    double rightTrigger = 0.0;
    if ( xbox != nullptr )
    {
        leftTrigger = xbox->GetAxisValue( IDragonGamePad::AXIS_IDENTIFIER::LEFT_TRIGGER );
        rightTrigger = xbox->GetAxisValue( IDragonGamePad::AXIS_IDENTIFIER::RIGHT_TRIGGER );
    }
    return ( rightTrigger - leftTrigger );
}

//=======================================================================
double GTADrive::GetSteer()
{
    auto xbox = GetXBox();
    return ( ( xbox != nullptr ) ? xbox->GetAxisValue( IDragonGamePad::AXIS_IDENTIFIER::LEFT_JOYSTICK_X) : 0.0 );
}


