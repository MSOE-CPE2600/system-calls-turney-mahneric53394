/**************************************************
* Lab 9
* Filename: pinfo.c
* Description: Reduce priority, sleep, and exit
* and determines things from it
* Author: Eric Mahn
* Section: 121
* Date: 11/11/24
* Compile Instructions: make
***************************************************/
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[])
{
    //Reduce priority by 10
    nice(10);

    // set the time to 1,837,272,638 nanoseconds
    struct timespec time;
    time.tv_sec = 1;
    time.tv_nsec = 837272638;

    //sleep for that time
    nanosleep(&time, NULL);

    //print and exit
    printf("Goodbye!\n");
    return 0;
}