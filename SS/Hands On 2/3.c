/*
============================================================================
Name : 3.c
Author : Parv Gatecha (MT2024108)
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 6 Sept, 2024.
============================================================================
*/

#include <stdio.h>      // Standard I/O library for printing messages
#include <stdlib.h>     // Standard library for general functions like exit()
#include <sys/resource.h> // Library for setting and getting resource limits

int main() {
    struct rlimit limit; // Declare a structure to hold the resource limits

    // Set the limit values for virtual memory
    // rlim_cur is the soft limit - this is the value that the OS enforces for resource usage
    limit.rlim_cur = 256 * 1024 * 1024;  // Setting soft limit to 256 MB (256 * 1024 * 1024 bytes)

    // rlim_max is the hard limit - the maximum value the soft limit can be raised to by the process
    limit.rlim_max = 256 * 1024 * 1024;  // Setting hard limit also to 256 MB

    // Apply the limit using setrlimit function
    // RLIMIT_AS is the resource we're limiting (the maximum size of the process's virtual memory)
    if (setrlimit(RLIMIT_AS, &limit) == -1) {
        // If setrlimit returns -1, an error occurred
        // perror prints a descriptive error message related to the last system call (setrlimit)
        perror("Error setting RLIMIT_AS");
        printf("rlim_cur: %ld, rlim_max: %ld\n", limit.rlim_cur, limit.rlim_max);
        return EXIT_FAILURE;
    }

    // If the limit was set successfully, print a confirmation message
    printf("Virtual memory limit set to 256 MB.\n");
    printf("rlim_cur: %ld, rlim_max: %ld\n", limit.rlim_cur, limit.rlim_max);


    // The following is an infinite loop that keeps the program running.
    // This is just to ensure that the program doesn't terminate immediately,
    // so that you can inspect the resource limit while the program is running.
    while (1) {
        // The loop does nothing - it just keeps the program alive.
        // You can add code here to simulate work if needed.
    }

    // Return statement in case the loop ever ends (it won't in this case)
    return 0;
}

/*
============================================================================
Command line: cc 3.c && ./a.out
Output: 
Virtual memory limit set to 256 MB.
rlim_cur: 268435456, rlim_max: 268435456
============================================================================
*/