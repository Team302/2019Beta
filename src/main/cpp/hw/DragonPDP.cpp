/*
 * DragonPDP.cpp
 */

#include <memory>

#include <hw/DragonPDP.h>
#include <frc/PowerDistributionPanel.h>

using namespace frc;
using namespace std;

DragonPDP* DragonPDP::m_instance = nullptr;

DragonPDP* DragonPDP::GetInstance()
{
	if ( DragonPDP::m_instance == nullptr )
	{
		DragonPDP::m_instance = new DragonPDP();
	}
	return DragonPDP::m_instance;
}
//=======================================================================================
// Method:  		CreatePDP
// Description:		Create a PDP from the inputs
// Returns:         std::shared_ptr<PowerDistributionPanel>
//=======================================================================================
shared_ptr<PowerDistributionPanel> DragonPDP::CreatePDP
(
	int			canID				// <I> - CANLight CAN ID
)
{
	DragonPDP::m_pdp = make_shared<PowerDistributionPanel>( canID );

	return DragonPDP::m_pdp;
}
