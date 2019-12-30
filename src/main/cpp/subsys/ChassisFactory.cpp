
#include <memory>

#include <subsys/IChassis.h>
#include <subsys/ChassisFactory.h>
#include <hw/interfaces/IDragonMotorController.h>

using namespace std;

ChassisFactory* ChassisFactory::m_chassisFactory = nullptr;
ChassisFactory* ChassisFactory::GetChassisFactory()
{
    if ( ChassisFactory::m_chassisFactory == nullptr )
    {
        ChassisFactory::m_chassisFactory = new ChassisFactory();
    }
    return ChassisFactory::m_chassisFactory;
}

shared_ptr<IChassis> ChassisFactory::GetIChassis()
{
    shared_ptr<IChassis> chassis = nullptr;
    return chassis;
}

//=======================================================================================
// Method:  		CreateChassis
// Description:		Create a chassis from the inputs
// Returns:         Void
//=======================================================================================
shared_ptr<IChassis> ChassisFactory::CreateChassis
(
    ChassisFactory::CHASSIS_TYPE   	    type,				// <I> - Chassis Type
    float 						        wheelDiameter,		// <I> - Diameter of the wheel
    float 					    	    wheelBase,			// <I> - Front-Back distance between wheel centers
    float 						        track,				// <I> - Left-Right distance between wheels (same axle)
	const IDragonMotorControllerMap&    motors 		        // <I> - Motor Controllers
)
{
    shared_ptr<IChassis> chassis = nullptr;
    return chassis;
}


