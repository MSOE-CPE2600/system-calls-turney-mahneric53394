/**************************************************
* Lab 9
* Filename: pinfo.c
* Description: Use system calls to print the
* information about a given file
* Author: Eric Mahn
* Section: 121
* Date: 11/11/24
* Compile Instructions: make 
***************************************************/
#define _GNU_SOURCE
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[])
{
    struct stat file_info;

    //check if a file was provided
    if (argc != 2) {
        printf("No File Provided\n");
        exit(1);
    }

    //check file information
    if (stat(argv[1], &file_info) == -1) {
        printf("Unable to obtain file information\n");
        exit(1);
    }

    //print the type of file
     if (S_ISREG(file_info.st_mode)) {
        printf("File Type: Regular File\n");
    } else if (S_ISDIR(file_info.st_mode)) {
        printf("File Type: Directory\n");
    } else if (S_ISLNK(file_info.st_mode)) {
        printf("File Type: Symbolic Link\n");
    } else if (S_ISCHR(file_info.st_mode)) {
        printf("File Type: Character Device\n");
    } else if (S_ISBLK(file_info.st_mode)) {
        printf("File Type: Block Device\n");
    } else if (S_ISFIFO(file_info.st_mode)) {
        printf("File Type: FIFO\n");
    } else if (S_ISSOCK(file_info.st_mode)) {
        printf("File Type: Socket\n");
    } else {
        printf("File Type: Unknown\n");
    }

    //print the file permissions
    printf((S_ISDIR(file_info.st_mode)) ? "Is a Directory\n" : "Is not a Directory\n");
    printf("User Permissions:  ");
    printf((file_info.st_mode & S_IRUSR) ? "r" : "-");
    printf((file_info.st_mode & S_IWUSR) ? "w" : "-");
    printf((file_info.st_mode & S_IXUSR) ? "x" : "-");
    printf("\n");
    printf("Group Permissions: ");
    printf((file_info.st_mode & S_IRGRP) ? "r" : "-");
    printf((file_info.st_mode & S_IWGRP) ? "w" : "-");
    printf((file_info.st_mode & S_IXGRP) ? "x" : "-");
    printf("\n");
    printf("Other Permissions: ");
    printf((file_info.st_mode & S_IROTH) ? "r" : "-");
    printf((file_info.st_mode & S_IWOTH) ? "w" : "-");
    printf((file_info.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    //print the owner
    printf("Owner UID: %d\n", file_info.st_uid);

    //print the size of the file
    printf("File Size: %ld\n", file_info.st_size);

    struct tm *time = localtime(&file_info.st_mtime);
    printf("Last Modification: %02d/%02d/%d %02d:%02d:%02d\n", time->tm_mon + 1, \
    time->tm_mday, time->tm_year + 1900, time->tm_hour, time->tm_min, time->tm_sec);

    return 0;
}