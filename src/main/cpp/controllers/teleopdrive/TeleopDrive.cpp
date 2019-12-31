
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
#include <controllers/teleopdrive/TeleopDrive.h>
#include <subsys/MechanismControl.h>
#include <gamepad/DragonXBox.h>
#include <subsys/IChassis.h>

using namespace std;

TeleopDrive::TeleopDrive
(
    shared_ptr<IChassis>    chassis,
    shared_ptr<DragonXBox>  xbox
) : m_chassis( chassis ),
    m_xbox( xbox ),
    m_leftPercent( 0.0 ),
    m_rightPercent( 0.0 )
{
}

void TeleopDrive::Drive()
{
    CalculateLeftRightPercents();
    m_chassis->SetOutput( MechanismControl::PERCENT_OUTPUT, m_leftPercent, m_rightPercent );
}

void TeleopDrive::SetLeftPercent( double percent )
{
    m_leftPercent = percent;
}

void TeleopDrive::SetRightPercent( double percent )
{
    m_rightPercent = percent;
}

shared_ptr<DragonXBox> TeleopDrive::GetXBox() const
{
    return m_xbox;
}

shared_ptr<IChassis> TeleopDrive::GetChassis() const
{
    return m_chassis;
}

