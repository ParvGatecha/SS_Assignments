/*
============================================================================
Name : 1a.c.c
Author : Parv Gatecha
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
                10micro second
                b. ITIMER_VIRTUAL
Date: 6 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>   // For signal handling
#include <sys/time.h> // For timers

// Signal handler for SIGVTALRM
void handle_virtual_alarm(int signum) {
    printf("Timer expired (ITIMER_VIRTUAL)\n");
}

int main() {
    struct itimerval timer; // Structure to hold timer settings

    // Set up the signal handler for SIGVTALRM (called when the timer expires)
    signal(SIGVTALRM, handle_virtual_alarm);

    // Set the initial timer value (10 seconds and 10 microseconds)
    timer.it_value.tv_sec = 10;    // Timer expires after 10 seconds
    timer.it_value.tv_usec = 10;   // 10 microseconds after the 10 seconds
    timer.it_interval.tv_sec = 10; // Timer will reset every 10 seconds
    timer.it_interval.tv_usec = 10;// 10 microseconds after each 10-second interval

    // Set the ITIMER_VIRTUAL timer (counts only when the process is running in user mode)
    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("Error setting ITIMER_VIRTUAL");
        exit(EXIT_FAILURE);
    }

    // Simulate some work in user mode by doing an infinite loop
    while (1) {
        // Do some user mode processing (e.g., calculations, etc.)
        /*
        The timer won't expire unless the process is actively doing something in user mode.
        So, without adding meaningful user-mode tasks, the timer will not trigger the signal and no output will be printed.
        */
        while(1){
            int i = 0;
            i++;
        }
    }

    return 0;
}

/*
============================================================================
Command line: cc 1b.c &&./a.out
Output: 
Timer expired (ITIMER_VIRTUAL)
Timer expired (ITIMER_VIRTUAL)
...
(every 10 sec 10 usec)
============================================================================
*/
