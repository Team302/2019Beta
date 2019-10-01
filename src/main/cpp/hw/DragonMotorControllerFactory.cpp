/*
 * DragonMotorControllerFactory.cpp
 *
 */
#include <iostream>

#include <subsys/IMechanism.h>
#include <hw/DragonMotorControllerFactory.h>        
#include <xmlhw/MotorDefn.h>
#include <hw/DragonTalon.h>
#include <hw/DragonSparkMax.h>

#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/phoenix/MotorControl/FeedbackDevice.h>
#include <rev/CANSparkMax.h>


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
	int size = IDragonMotorController::MOTOR_CONTROLLER_TYPE::MAX_MOTOR_CONTROLLER_TYPES;
	m_usageControllers.resize( size );
	m_mechanism.resize( size );
	for ( auto inx=0; inx<size; ++inx )
	{
		m_usageControllers[inx] = nullptr;
		m_mechanism[inx] = IMechanism::MECHANISM_TYPE::UNKNOWN_MECHANISM;
	}
	for ( auto inx=0; inx<63; ++inx )
	{
		m_canControllers[inx] = nullptr;
	}
}

//=======================================================================================
// Method:          CreateMotorController
// Description:     Create a motor controller from the inputs
// Returns:         Void
//=======================================================================================
IDragonMotorController* DragonMotorControllerFactory::CreateMotorController
(
	IMechanism::MECHANISM_TYPE						mechtype, 
	DragonMotorControllerFactory::MOTOR_TYPE		mtype,
    int 											canID,
	int 											pdpID,
    IDragonMotorController::MOTOR_CONTROLLER_TYPE   usage,
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
	printf("In DragonMotorControllerFactory beginning of constructor\n");
    IDragonMotorController* controller = nullptr;
	
	switch ( mtype )
	{
		case MOTOR_TYPE::TALONSRX:
		{
			// TODO:: set PDP ID
			auto talon = new DragonTalon( usage, canID, countsPerRev, gearRatio );
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
			controller = talon;         
		}
		break;

		case MOTOR_TYPE::BRUSHLESS_SPARK_MAX:
		{
			// TODO:: set PDP ID
			auto smax = new DragonSparkMax( canID, usage, CANSparkMax::MotorType::kBrushless, gearRatio );
			smax->Invert( inverted );
			smax->EnableBrakeMode( brakeMode );
			smax->InvertEncoder( sensorInverted );
			smax->EnableCurrentLimiting( enableCurrentLimit );
			smax->SetSmartCurrentLimiting( continuousCurrentLimit );
			printf("Setting SparkMax current limit to %d\n", continuousCurrentLimit);

			if ( slaveTo > -1 )
			{
				DragonSparkMax* master = nullptr;
				if ( GetController( slaveTo ) != nullptr )
				{
					master = dynamic_cast<DragonSparkMax*>( GetController( slaveTo ) );
				}
				if ( master != nullptr )
				{
					smax->Follow( master );
				}
				else 
				{
					printf( "Invalid SlaveTo id %d \n", slaveTo );
				}
			}    
			controller = smax;           
		} 
		break;

		case MOTOR_TYPE::BRUSHED_SPARK_MAX:
		{
			// TODO:: set PDP ID
			auto smax = new DragonSparkMax( canID, usage, CANSparkMax::MotorType::kBrushed , gearRatio );
			smax->Invert( inverted );
			smax->EnableBrakeMode( brakeMode );
			smax->InvertEncoder( sensorInverted );
			smax->EnableCurrentLimiting( enableCurrentLimit );

			if ( slaveTo > -1 )
			{
				DragonSparkMax* master = nullptr;
				if ( GetController( slaveTo ) != nullptr )
				{
					master = dynamic_cast<DragonSparkMax*>( GetController( slaveTo ) );
				}
				if ( master != nullptr )
				{
					smax->Follow( master );
				}
				else 
				{
					printf( "Invalid SlaveTo id %d \n", slaveTo );
				}
			}
			controller = smax;
		}            
		break;

		default:
			break;
	}
	m_canControllers[ canID ] = controller;
	m_usageControllers[ usage ] = controller;
	m_mechanism[ usage ] = mechtype;
	printf("In DragonMotorControllerFactory end of constructor\n");
	return controller;
}



//=======================================================================================
// Method:          GetController
// Description:     return motor controller
// Returns:         IDragonMotorController* 	may be nullptr if there isn't a controller
//												with this CAN ID.
//=======================================================================================
IDragonMotorController* DragonMotorControllerFactory::GetController
(
	int							canID		/// Motor controller CAN ID
)
{
	IDragonMotorController* controller = nullptr;
	if ( canID > -1 && canID < 63 )
	{
		controller = m_canControllers[ canID ];
	}
	else
	{
		std::cout << "==>> DragonMotorControllerFactory::GetController invalid CAN ID " << canID << "\n";
	}
	return controller;
}

//=======================================================================================
// Method:          GetController
// Description:     return motor controller
// Returns:         IDragonMotorController* 	may be nullptr if there isn't a controller
//												with this CAN ID.
//=======================================================================================
IDragonMotorController* DragonMotorControllerFactory::GetController
(
	IMechanism::MECHANISM_TYPE							subsys,		/// system using the motor
	IDragonMotorController::MOTOR_CONTROLLER_TYPE     	usage		/// Motor usage (e.g. Front Left Drive Motor)
)
{
	IDragonMotorController* controller = nullptr;
	int slot = usage;
	if ( slot < m_usageControllers.size() )
	{
		controller = m_usageControllers[ slot ];
		if ( subsys != m_mechanism[ slot ] )
		{
			std::cout << "==>>DragonMotorControllerFactory::GetController mismatched mechanism " << subsys << "\n";
		}
	}
	else
	{
		std::cout << "==>>DragonMotorControllerFactory::GetController invalid usage requested " << usage << "\n";
	}

	return controller;
}
