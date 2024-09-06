/*
============================================================================
Name : 1a.c.c
Author : Parv Gatecha
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
                10micro second
                c. ITIMER_PROF
Date: 6 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>   // For signal handling
#include <sys/time.h> // For timers

// Signal handler for SIGPROF
void handle_prof_alarm(int signum) {
    printf("Timer expired (ITIMER_PROF)\n");
}

int main() {
    struct itimerval timer; // Structure to hold timer settings

    // Set up the signal handler for SIGPROF (called when the timer expires)
    signal(SIGPROF, handle_prof_alarm);

    // Set the initial timer value (10 seconds and 10 microseconds)
    timer.it_value.tv_sec = 10;    // Timer expires after 10 seconds
    timer.it_value.tv_usec = 10;   // 10 microseconds after the 10 seconds
    timer.it_interval.tv_sec = 10; // Timer will reset every 10 seconds
    timer.it_interval.tv_usec = 10;// 10 microseconds after each 10-second interval

    // Set the ITIMER_PROF timer (counts both user mode and system mode time)
    if (setitimer(ITIMER_PROF, &timer, NULL) == -1) {
        perror("Error setting ITIMER_PROF");
        exit(EXIT_FAILURE);
    }

    // Simulate some work in user and kernel mode by doing an infinite loop
    while (1) {
        // Do some user mode and system mode processing
    }

    return 0;
}

/*
============================================================================
Command line: cc 1c.c &&./a.out
Output: 
Timer expired (ITIMER_PROF)
Timer expired (ITIMER_PROF)
...
(every 10 sec 10 usec)
============================================================================
*/
