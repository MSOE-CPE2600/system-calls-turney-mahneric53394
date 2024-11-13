/**************************************************
* Lab 9
* Filename: info.c
* Description: prints system information.
* Author: Eric Mahn
* Section: 121
* Date: 11/11/24
* Compile Instructions: make 
***************************************************/
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>

int main(int argc, char* argv[])
{

    //create a timespec structure to hold the itme
    struct timespec ts;
    //get the current time
    clock_gettime(CLOCK_REALTIME, &ts);

    struct tm *time = localtime(&ts.tv_sec);

    double time_nano = (time->tm_hour * 3600 + time->tm_min * 60 + time->tm_sec) * 1e9 + ts.tv_nsec;
    //print the time in nanoseconds
    printf("Current time in nanoseconds: %.0f\n", time_nano);

    //get the hostname and print it
    char name[256];
    gethostname(name, sizeof(name));
    printf("The system's network name is: %s\n", name);

    //create a utsname structure
    struct utsname uname_data;
    //get the system information
    uname(&uname_data);

    //print information
    printf("The operating system name is: %s\n", uname_data.sysname);
    printf("The operating system release is: %s\n", uname_data.release);
    printf("The operation system version is: %s\n", uname_data.version);
    printf("The operation system hardware type is: %s\n", uname_data.machine);

    //get the number of cpus and print it
    int num_CPU = get_nprocs();
    printf("The number of CPUs is: %d\n", num_CPU);

    //get the memory information
    long page_size = getpagesize();
    long total_pages = sysconf(_SC_PHYS_PAGES);
    long available_pages = sysconf(_SC_AVPHYS_PAGES);

    printf("Page Size: %ld\n", page_size);
    printf("Total physical memory:  %ld\n", page_size * total_pages);
    printf("Total available memory: %ld\n", page_size * available_pages);

    return 0;
}