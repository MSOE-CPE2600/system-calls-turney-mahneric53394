# system-calls

## info.c

The info.c file uses system calls to print various 
information of your current system.

## pinfo.c

The pinfo.c file gets the process priority and policy of
a PID. A PID can be given as a command argument, or
no command line will just us the current PID.

## pmod.c

The pmod.c file uses the nice function to reduce the priority
by 10, then sleeps for 1,837,272,638 nano seconds, sends
a message then exists.

## finfo.c

The finfo.c file uses system calls to list the information of
a file 