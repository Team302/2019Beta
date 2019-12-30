*************************************************************************************************************
 #  Team 302 FIRST Robot Template Project
*************************************************************************************************************

This has the base code that will allow competition specific code to be developed quickly and reliably.  This started as a template directory, but evolved into our beta test repository for 2019 Control System Beta, so it was renamed appropriately.   Additional code items was pulled in besides the template stuff to test with the various robots available.

The key components are:

## Robot Configuration via XML file
The config folder contains:
- **DTD files** are in the main folder since they are shared
- **XML files** are in sub-folders based on the robot.  These files get deployed at the same level as the DTD files on the robot.

### Robot Hardware Files 
- **Robot.dtd** defines the structure for defining a configurable robot.
- **Robot.xml** defines the specific hardware and mechanisms on a particular robot.  Thus, the practice robot and the compentition    robot could be almost exactly the same with maybe different CAN IDs or motor inversions or they could have different or missing mechanisms.   This file indicates all of this information.
   
These files are parsed using the cpp/xmlhw files.  As the files get parsed  a couple of types of objects are created:
- The hardware components (motor controllers and sensors) get created.  These are found in cpp/hw.
- Subsystems (e.g. chassis and mechanisms) that contain the hardware components also get created.  These are found in cpp/subsys.

### Robot Mechanism Parameter Files 
These files contain the mechanism data (xml files using the mechdata.dtd as its definition).  This allows mechanisms to get things like pre-defined locations from XML files without having to understand the file parsing. 

Just edit this file and restart robot code.

- **mechdata.dtd** defines the format (attributes/elements) for the XML files that define the parematers for mechanisms such as pre-defined set positions
- **XXX_data.xml** defines the specific parameters for mechanisms

### Robot Mechanism Control Parameter Files 
- **control.dtd** defines the format (attributes/elements) for the XML files that define the PID control parameters
- **XXX_Control.xml** defines the control parameters for mechanism (class) XXX


## XML file parsing leveraging Open Source Program PUGIXML 
As noted above:
- cpp/xmlhw parses the Robot hardware data and creates objects that reside in either cpp/hw or cpp/subsys.
- cpp/xmlmechdata parses the Mechanism Parameter data
- cpp/xmlcontrol parses the Mechanism Control parameter data

## Hardware wrappers that get created from the XML parsing that provide some additional capabilities from the 
   base hardware classes provided by WPI, CTRE, REV
   
## Structure for Mechanisms definitions

## Human Interface Devices (HIDs) which wrap the classes provided and provide a logical mapping interface
   so that the various classes don't have to know which button/axis is used for their function.  Rather they
   merely ask this layer if the XXX function button is pressed where XXX is their function.  This makes it 
   much easier to move the mappings around as we tune to the drive team or add more capabilities.
