/*
============================================================================
Name : 8a.c
Author : Parv Gatecha (MT2024108)
Description : Write a separate program using signal system call to catch the following signals.
                a. SIGSEGV
                b. SIGINT
                c. SIGFPE
                d. SIGALRM (use alarm system call)
                e. SIGALRM (use setitimer system call)
                f. SIGVTALRM (use setitimer system call)
                g. SIGPROF (use setitimer system call)
Date: 10 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// Signal handler function for SIGSEGV (Segmentation Fault)
void handle_sigsegv(int sig) {
    printf("Caught SIGSEGV: Segmentation Fault\n");
    exit(1);  // Exit the program after catching the signal
}

int main() {
    // Register the signal handler for SIGSEGV
    signal(SIGSEGV, handle_sigsegv);

    // Intentionally cause a segmentation fault by dereferencing a NULL pointer
    int *ptr = NULL;
    *ptr = 42;  // This will trigger SIGSEGV

    return 0;
}

/*
============================================================================
Command line: cc 8a.c && ./a.out
Output: 
Caught SIGSEGV: Segmentation Fault
============================================================================
*/
