*************************************************************************************************************
 #  Team 302 FIRST robot - Control Data Parsing
*************************************************************************************************************

This code will:
1. Read an xml file that uses control.dtd
2. Create PIDData objects

Thus, clients (mechanisms) can get the control information without needing to read XML files.  The advantage 
is when tuning these control parameters, we don't have to go through code recompiles; all we do is make changes
via filezilla (or some other remote editing/transfer tool) and then restart robot code.   This is an alternative 
to some other methods we have tried such as using the smart dashboard which seemed to have delays, so we weren't
confident that it actually took.


