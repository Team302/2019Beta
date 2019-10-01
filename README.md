*************************************************************************************************************
   Team 302 FIRST robot Template Project
*************************************************************************************************************

This has the base code that will allow competition specific code to be developed quickly and reliably.  The 
key components are:
1) Robot Configuration via XML file
2) XML file parsing leveraging Open Source Program PUGIXML
3) Hardware wrappers that get created from the XML parsing that provide some additional capabilities from the 
   base hardware classes provided by WPI, CTRE, REV
4) Structure for Mechanisms definitions
5) Human Interface Devices (HIDs) which wrap the classes provided and provide a logical mapping interface
   so that the various classes don't have to know which button/axis is used for their function.  Rather they
   merely ask this layer if the XXX function button is pressed where XXX is their function.  This makes it 
   much easier to move the mappings around as we tune to the drive team or add more capabilities.
