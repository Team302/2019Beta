
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
#include <map>
#include <memory>

// FRC includes

// Team 302 includes
#include <hw/interfaces/IDragonMotorController.h>
#include <hw/usages/MotorControllerUsage.h>
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

    // See if the mechanism was created already, if it wasn't create it
    auto it = m_mechanisms.find( type );  
    if ( it != m_mechanisms.end() )      //  found
    {
        subsys = it->second;
    }
    else
    {
        // Create the mechanism
        switch ( type )
        {
            case MechanismTypes::MECHANISM_TYPE::CHASSIS:
            break;

            case MechanismTypes::MECHANISM_TYPE::SHOOTER:
            break;

            case MechanismTypes::MECHANISM_TYPE::ELEVATOR:
            break;

            case MechanismTypes::MECHANISM_TYPE::WRIST:
            break;

            case MechanismTypes::MECHANISM_TYPE::INTAKE:
            break;

            case MechanismTypes::MECHANISM_TYPE::ARM:
            break;

            case MechanismTypes::MECHANISM_TYPE::EXTENDER:
            break;

            case MechanismTypes::MECHANISM_TYPE::CLIMBER:
            break;

            case MechanismTypes::MECHANISM_TYPE::BEAK:
            break;

            case MechanismTypes::MECHANISM_TYPE::TAIL:
            break;

            default:
            break;
        }
    }

	return subsys;
}



//=====================================================================================
/// Method:         CreateIMechanism
/// Description:    Find or create the requested mechanism
/// Returns:        IMechanism*     pointer to the mechanism or nullptr if mechanism 
///                                 doesn't exist and cannot be created.
//=====================================================================================
shared_ptr<IMechanism>  MechanismFactory::CreateIMechanism
(
	MechanismTypes::MECHANISM_TYPE			type,
    const IDragonMotorControllerMap&        motorControllers,   // <I> - Motor Controllers
    const DragonSolenoidVector&             solenoids,          // <I> - Solenoids
    const DragonDigitalInputVector&         digitalInputs,      // <I> - Digital Inputs
    const DragonAnalogInputVector&          analogInputs,       // <I> - Analog Inputs
    const DragonServoVector&                servos              // <I> - servos

)
{
	shared_ptr<IMechanism> subsys = nullptr;

    // See if the mechanism was created already, if it wasn't create it
    auto it = m_mechanisms.find( type );  
    if ( it != m_mechanisms.end() )      //  found
    {
        subsys = it->second;
    }
    else
    {
        // Create the mechanism
        switch ( type )
        {
            case MechanismTypes::MECHANISM_TYPE::CHASSIS:
            break;

            case MechanismTypes::MECHANISM_TYPE::SHOOTER:
            break;

            case MechanismTypes::MECHANISM_TYPE::ELEVATOR:
            break;

            case MechanismTypes::MECHANISM_TYPE::WRIST:
            break;

            case MechanismTypes::MECHANISM_TYPE::INTAKE:
            break;

            case MechanismTypes::MECHANISM_TYPE::ARM:
            break;

            case MechanismTypes::MECHANISM_TYPE::EXTENDER:
            break;

            case MechanismTypes::MECHANISM_TYPE::CLIMBER:
            break;

            case MechanismTypes::MECHANISM_TYPE::BEAK:
            break;

            case MechanismTypes::MECHANISM_TYPE::TAIL:
            break;

            default:
            break;
        }
    }

	return subsys;
}




