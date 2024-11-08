/*
============================================================================
Name : 2.c
Author : Parv Gatecha (MT2024108)
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 6 Sept, 2024.
============================================================================
*/

#include <stdio.h>      // For input/output operations (printf)
#include <sys/resource.h> // For getrlimit and rlimit structure
#include <stdlib.h>     // For exit() function

// Function to print the resource limits for a specific resource
// 'resource' is the type of resource (like CPU, memory, etc.)
// 'name' is a string to identify the resource when printing
void print_limit(int resource, const char* name) {
    struct rlimit limit;  // This structure will hold the limits for the resource

    // getrlimit fetches the soft and hard limits for a resource
    // If the call is successful, it returns 0
    if (getrlimit(resource, &limit) == 0) {
        // Print the resource name
        printf("%s:\n", name);
        
        // Print the soft limit (the current effective limit for the process)
        printf("  Soft limit: %ld\n", (long) limit.rlim_cur);
        
        // Print the hard limit (the maximum limit that can be set for the resource)
        printf("  Hard limit: %ld\n", (long) limit.rlim_max);
    } else {
        // If getrlimit fails, print an error message
        perror("getrlimit");
        exit(EXIT_FAILURE); // Exit the program with an error code
    }
}

int main() {
    // For each resource, we call the print_limit function and pass the resource type and a descriptive name.

    // CPU Time (the maximum amount of CPU time the process can use in seconds)
    print_limit(RLIMIT_CPU, "CPU Time (seconds)");

    // File Size (the maximum size of a file the process can create, in bytes)
    print_limit(RLIMIT_FSIZE, "File Size (bytes)");

    // Data Segment Size (the maximum size of the data segment, which includes heap memory)
    print_limit(RLIMIT_DATA, "Data Segment Size (bytes)");

    // Stack Size (the maximum size of the process stack, which is used for function calls and local variables)
    print_limit(RLIMIT_STACK, "Stack Size (bytes)");

    // Core File Size (the maximum size of a core dump file that can be created if the process crashes)
    print_limit(RLIMIT_CORE, "Core File Size (bytes)");

    // Resident Set Size (the maximum amount of physical memory the process can use)
    print_limit(RLIMIT_RSS, "Resident Set Size (bytes)");

    // Maximum Number of File Descriptors (the maximum number of files a process can have open at one time)
    print_limit(RLIMIT_NOFILE, "Max Number of File Descriptors");

    // Locked Memory (the maximum amount of memory that can be locked in RAM)
    print_limit(RLIMIT_MEMLOCK, "Locked Memory (bytes)");

    // Maximum Number of Processes (the maximum number of processes a user can create)
    print_limit(RLIMIT_NPROC, "Max Number of Processes");

    // Address Space (the maximum amount of virtual memory the process can use)
    print_limit(RLIMIT_AS, "Address Space (bytes)");

    return 0;  // Return 0 to indicate successful execution
}

/*
/*
============================================================================
Command line: cc 2.c && ./a.out
Output: 
CPU Time (seconds):
  Soft limit: -1       //(-1 means unlimited)
  Hard limit: -1
File Size (bytes):
  Soft limit: -1
  Hard limit: -1
Data Segment Size (bytes):
  Soft limit: -1
  Hard limit: -1
Stack Size (bytes):
  Soft limit: 8388608
  Hard limit: -1
Core File Size (bytes):
  Soft limit: 0
  Hard limit: -1
Resident Set Size (bytes):
  Soft limit: -1
  Hard limit: -1
Max Number of File Descriptors:
  Soft limit: 1024
  Hard limit: 1048576
Locked Memory (bytes):
  Soft limit: 2019119104
  Hard limit: 2019119104
Max Number of Processes:
  Soft limit: 61340
  Hard limit: 61340
Address Space (bytes):
  Soft limit: -1
  Hard limit: -1
============================================================================
*/