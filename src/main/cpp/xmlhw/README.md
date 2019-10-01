*************************************************************************************************************
 #  Team 302 FIRST robot 
 ## Robot Definition
*************************************************************************************************************

These files will parse the Robot.xml file that usese Robot.dtd as its definition.  This defines the mechanisms that 
are on the robot, which hardware is used, etc.   So, for instance, the same code can run on the practice robot and 
the competition robot.  This file will control which mechanisms are available, motor inversions, what CAD ID or I/O slot 
the hardware is plugged into, etc.

The only requirement is that the code itself follows good coding practices and checks for a nullptr before using
it (e.g. we would get an error if there wasn't any intake mechanism, but the code blindly assumed that when they 
asked for the intake mechanism that it wasn't a nullptr\).
