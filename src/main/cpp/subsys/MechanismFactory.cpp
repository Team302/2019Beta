
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

//========================================================================================================
/// MechanismFactory.cpp
//========================================================================================================
///
/// File Description:
///     This controls the creation of mechanisms/subsystems
///
//========================================================================================================

// C++ Includes
#include <memory>

// FRC includes

// Team 302 includes
#include <subsys/MechanismFactory.h>
#include <subsys/IMechanism.h>
#include <subsys/MechanismTypes.h>


// Third Party Includes


using namespace std;


//=====================================================================================
/// Method:         GetMechanismFactory
/// Description:    Find or create the mechanism factory
/// Returns:        MechanismFactory* pointer to the mechanism factory
//=====================================================================================
MechanismFactory* MechanismFactory::m_mechanismFactory = nullptr;
MechanismFactory* MechanismFactory::GetMechanismFactory()
{
	if ( MechanismFactory::m_mechanismFactory == nullptr )
	{
		MechanismFactory::m_mechanismFactory = new MechanismFactory();
	}
	return MechanismFactory::m_mechanismFactory;
}

//=====================================================================================
/// Method:         GetIMechanism
/// Description:    Find or create the requested mechanism
/// Returns:        IMechanism*     pointer to the mechanism or nullptr if mechanism 
///                                 doesn't exist and cannot be created.
//=====================================================================================
shared_ptr<IMechanism>  MechanismFactory::GetIMechanism
(
	MechanismTypes::MECHANISM_TYPE			type		// <I> - manipulator type
)
{
	shared_ptr<IMechanism> subsys = nullptr;

    switch ( type )
    {
        case MechanismTypes::WRIST:
        break;

        case MechanismTypes::INTAKE:
        break;

        case MechanismTypes::ARM:
        break;

        case MechanismTypes::EXTENDER:
        break;

        case MechanismTypes::CLIMBER:
        break;

        case MechanismTypes::BEAK:
        break;

        case MechanismTypes::TAIL:
        break;

        default:
        break;
    }

	return subsys;
}



//=====================================================================================
/// Method:         MechanismFactory
/// Description:    Constructor for this singleton factory that initialized memory usage
//=====================================================================================
MechanismFactory::MechanismFactory() 
{
    m_wrist    = nullptr;
	m_arm      = nullptr;
	m_extender = nullptr;
	m_climber  = nullptr;
	m_beak     = nullptr;
	m_tail     = nullptr;
}


//=====================================================================================
/// Method:         ~MechanismFactory
/// Description:    Destructor for this singleton factory that cleans up memory usage
//=====================================================================================
MechanismFactory::~MechanismFactory()
{
    if ( m_wrist != nullptr )
    {
        delete m_wrist;
    }
    if ( m_arm != nullptr )
    {
        delete m_arm;
    }
    if ( m_extender != nullptr )
    {
        delete m_extender;
    }    
    if ( m_climber != nullptr )
    {
        delete m_climber;
    }
    if ( m_beak != nullptr )
    {
        delete m_beak;
    }
    if ( m_tail != nullptr )
    {
        delete m_tail;
    }
}

