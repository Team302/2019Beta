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
#include <xmlcontrol/PIDData.h>

PIDData::PIDData
(
    CONTROL_MODE            mode,
    PID_TARGET              pidTarget,
    double                  proportional,
    double                  integral,
    double                  derivative,
    double                  feedforward,
    double                  maxAcceleration,
    double                  cruiseVelocity
) : m_mode( mode ),
    m_pidTarget( pidTarget ),
    m_proportional( proportional ),
    m_integral( integral ),
    m_derivative( derivative ),
    m_feedforward( feedforward ),
    m_maxAcceleration( maxAcceleration ),
    m_cruiseVelocity( cruiseVelocity )
{

}
