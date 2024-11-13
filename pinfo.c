/**************************************************
* Lab 9
* Filename: pinfo.c
* Description: Takes a single PID command line
* and determines things from it
* Author: Eric Mahn
* Section: 121
* Date: 11/11/24
* Compile Instructions: make 
***************************************************/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>


int main(int argc, char* argv[])
{
    pid_t pid;
    int priority;
    int policy;

    //check if an argument was given
    if (argc > 1) {
        pid = atoi(argv[1]);
        //is it a valid PID?
        if(pid <= 0) {
            printf("Invalid PID\n");
            exit(1);
        }
    } 
    //if an argument was not given
    else {
        pid = getpid();
    }

    //get the priority
    priority = getpriority(PRIO_PROCESS, pid);

    printf("PID: %d\n", pid);
    printf("Process priority: %d\n", priority);

    //get the policy
    policy = sched_getscheduler(pid);

    //determine which policy it is to print the string, not int
    switch(policy) {
        case SCHED_OTHER:
            printf("Policy: SCHED_OTHER\n");
            break;
        case SCHED_BATCH:
            printf("Policy: SCHED_BATCH\n");
            break;
        case SCHED_IDLE:
            printf("Policy: SCHED_IDLE\n");
            break;
        case SCHED_FIFO:
            printf("Policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Policy: SCHED_RR\n");
            break;
        default:
            printf("Unknown Policy\n");
    }

    return 0;
}