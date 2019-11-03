/*
 * DragonPDP.h
 */

#pragma once

#include <memory>
#include <frc/PowerDistributionPanel.h>

using namespace frc;

class DragonPDP
{
	public:
		static DragonPDP* GetInstance();

		//=======================================================================================
		// Method:  		CreatePDP
		// Description:		Create a PDP from inputs
		// Returns:         std::shared_ptr<PowerDistributionPanel>
		//=======================================================================================
		std::shared_ptr<PowerDistributionPanel> CreatePDP
		(
			int			canID				// <I> - PDP CAN ID
		);

		inline std::shared_ptr<frc::PowerDistributionPanel> GetPDP() { return m_pdp;}

	private:
		DragonPDP() = default;
		virtual ~DragonPDP() = default;

		static DragonPDP*      				            m_instance;
		std::shared_ptr<frc::PowerDistributionPanel>    m_pdp;

};


