/*
 * DragonMotorControllerFactory.cpp
 *
 */
#include <iostream>
#include <map>
#include <string>

#include <subsys/IMechanism.h>
#include <hw/DragonMotorControllerFactory.h>        
#include <xmlhw/MotorDefn.h>
#include <hw/DragonTalon.h>
#include <hw/DragonSparkMax.h>
#include <utils/Logger.h>

#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/phoenix/MotorControl/FeedbackDevice.h>
#include <rev/CANSparkMax.h>

using namespace std;

DragonMotorControllerFactory* DragonMotorControllerFactory::m_instance = nullptr;


DragonMotorControllerFactory* DragonMotorControllerFactory::GetInstance()
{
    if ( DragonMotorControllerFactory::m_instance == nullptr )
    {
        DragonMotorControllerFactory::m_instance = new DragonMotorControllerFactory();
    }
    return DragonMotorControllerFactory::m_instance;
}

DragonMotorControllerFactory::DragonMotorControllerFactory() 
{
	for ( auto inx=0; inx<63; ++inx )
	{
		m_canControllers[inx] = nullptr;
	}
    CreateUsageMap();
    CreateTypeMap();
}

//=======================================================================================
// Method:          CreateMotorController
// Description:     Create a motor controller from the inputs
// Returns:         Void
//=======================================================================================
shared_ptr<IDragonMotorController> DragonMotorControllerFactory::CreateMotorController
(
	string		                                    mtype,
    int 											canID,
	int 											pdpID,
    string                                          usage,
    bool 											inverted, 
    bool 											sensorInverted,
    ctre::phoenix::motorcontrol::FeedbackDevice  	feedbackDevice,
    int 											countsPerRev,
    float 											gearRatio,
    bool 											brakeMode,
    int 											slaveTo,
    int 											peakCurrentDuration,
    int 											continuousCurrentLimit,
    int 											peakCurrentLimit,
    bool 											enableCurrentLimit
)
{
    shared_ptr<IDragonMotorController> controller;

    auto hasError = false;

    auto type = m_typeMap.find(mtype)->second;
    if ( type == MOTOR_TYPE::TALONSRX )
    {
        // TODO:: set PDP ID
        auto talon = new DragonTalon(m_usageMap.find(usage)->second, canID, countsPerRev, gearRatio );
        talon->EnableBrakeMode( brakeMode );
        talon->Invert( inverted );
        talon->SetSensorInverted( sensorInverted );
        talon->ConfigSelectedFeedbackSensor( feedbackDevice, 0, 50 );
        talon->ConfigSelectedFeedbackSensor( feedbackDevice, 1, 50 );

        talon->ConfigPeakCurrentLimit( peakCurrentLimit, 50 );
        talon->ConfigPeakCurrentDuration( peakCurrentDuration, 50 );
        talon->ConfigContinuousCurrentLimit( continuousCurrentLimit, 50 );
        talon->EnableCurrentLimiting( enableCurrentLimit );

        if ( slaveTo > -1 )
        {
            talon->SetAsSlave( slaveTo );
        }
        controller.reset( talon );
    }
    else if ( type == MOTOR_TYPE::BRUSHED_SPARK_MAX || type == MOTOR_TYPE::BRUSHLESS_SPARK_MAX )
    {
        auto brushedBrushless = (type == MOTOR_TYPE::BRUSHED_SPARK_MAX) ? CANSparkMax::MotorType::kBrushed : CANSparkMax::MotorType::kBrushless;
        auto smax = new DragonSparkMax( canID, m_usageMap.find(usage)->second, brushedBrushless, gearRatio );
        smax->Invert( inverted );
        smax->EnableBrakeMode( brakeMode );
        smax->InvertEncoder( sensorInverted );
        smax->EnableCurrentLimiting( enableCurrentLimit );
        smax->SetSmartCurrentLimiting( continuousCurrentLimit );
        if ( slaveTo > -1 )
        {
            DragonSparkMax* master = nullptr;
            if ( GetController( slaveTo ) != nullptr )
            {
                master = dynamic_cast<DragonSparkMax*>( GetController( slaveTo ).get() );
            }
            if ( master != nullptr )
            {
                smax->Follow( master );
            }
            else
            {
                string msg = "invalid Slave to ID ";
                msg += to_string( slaveTo );
                Logger::GetLogger()->LogError( "DragonMotorControllerFactory::CreateMotorController", msg );
            }
        }
        controller.reset( smax );
    }
    else
    {
        hasError = true;
    }

    if ( !hasError )
    {
        m_canControllers[ canID ] = controller;
    }
	return controller;
}



//=======================================================================================
// Method:          GetController
// Description:     return motor controller
// Returns:         IDragonMotorController* 	may be nullptr if there isn't a controller
//												with this CAN ID.
//=======================================================================================
shared_ptr<IDragonMotorController> DragonMotorControllerFactory::GetController
(
	int							canID		/// Motor controller CAN ID
) const
{
	shared_ptr<IDragonMotorController> controller;
	if ( canID > -1 && canID < 63 )
	{
		controller = m_canControllers[ canID ];
	}
	else
	{
	    string msg = "invalid CAN ID ";
	    msg += to_string( canID );
        Logger::GetLogger()->LogError( "DragonMotorControllerFactory::GetController", msg );
	}
	return controller;
}

void DragonMotorControllerFactory::CreateUsageMap()
{
    m_usageMap["FRONT_LEFT_DRIVE"]  = MOTOR_CONTROLLER_USAGE::FRONT_LEFT_DRIVE;
    m_usageMap["MIDDLE_LEFT_DRIVE"] = MOTOR_CONTROLLER_USAGE::MIDDLE_LEFT_DRIVE;
    m_usageMap["BACK_LEFT_DRIVE"]   = MOTOR_CONTROLLER_USAGE::BACK_LEFT_DRIVE;

    m_usageMap[ "FRONT_RIGHT_DRIVE"] = MOTOR_CONTROLLER_USAGE::FRONT_RIGHT_DRIVE;
    m_usageMap["MIDDLE_RIGHT_DRIVE"] = MOTOR_CONTROLLER_USAGE::MIDDLE_RIGHT_DRIVE;
    m_usageMap["BACK_RIGHT_DRIVE"]   = MOTOR_CONTROLLER_USAGE::BACK_RIGHT_DRIVE;

    m_usageMap["ARM_MASTER"]    = MOTOR_CONTROLLER_USAGE::ARM_MASTER;
    m_usageMap["ARM_SLAVE"]     = MOTOR_CONTROLLER_USAGE::ARM_SLAVE;
    m_usageMap["ARM_EXTENSION"] = MOTOR_CONTROLLER_USAGE::ARM_EXTENSION;

    m_usageMap["WRIST"] = MOTOR_CONTROLLER_USAGE::WRIST;

    m_usageMap["INTAKE"] = MOTOR_CONTROLLER_USAGE::INTAKE;

    m_usageMap["ELEVAtOR_WINCH"]  = MOTOR_CONTROLLER_USAGE::ELEVATOR_WINCH;
    m_usageMap["ELEVATOR_DrIVE"]  = MOTOR_CONTROLLER_USAGE::ELEVATOR_DRIVE;

    m_usageMap["HATCH_MECH_MOTOR"] = MOTOR_CONTROLLER_USAGE::HATCH_MECH_MOTOR;
}


void DragonMotorControllerFactory::CreateTypeMap()
{
    m_typeMap["TALONSRX"] = DragonMotorControllerFactory::MOTOR_TYPE::TALONSRX;
    m_typeMap["BRUSHLESS_SPARK_MAX"] = DragonMotorControllerFactory::MOTOR_TYPE::BRUSHLESS_SPARK_MAX;
    m_typeMap["BRUSHED_SPARK_MAX"] = DragonMotorControllerFactory::MOTOR_TYPE::BRUSHED_SPARK_MAX;
}
