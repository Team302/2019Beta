/*
 * DragonAnalogInput.h
 */

#ifndef SRC_SUBSYS_COMPONENTS_DRAGONANALOGINPUT_H_
#define SRC_SUBSYS_COMPONENTS_DRAGONANALOGINPUT_H_

#include <vector>
#include <frc/AnalogInput.h>
#include <hw/usages/AnalogInputUsage.h>

using namespace frc;

class DragonAnalogInput : AnalogInput
{
	public:
		DragonAnalogInput
		(
			ANALOG_SENSOR_USAGE			type,
			int 						analogID,
		    float						voltageMin,
		    float						voltageMax,
		    float 						outputMin,
		    float						outputMax
		);
		virtual ~DragonAnalogInput();
		double GetInterpolatedValue() const;

	private:
		ANALOG_SENSOR_USAGE				m_type;
		float							m_voltMin;
		float							m_voltMax;
		float							m_outMin;
		float							m_outMax;
};
typedef std::vector<DragonAnalogInput*> DragonAnalogInputVector;

#endif /* SRC_SUBSYS_COMPONENTS_DRAGONANALOGINPUT_H_ */
