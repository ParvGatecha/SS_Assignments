/*
============================================================================
Name : 13a.c
Author : Parv Gatecha (MT2024108)
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
                will send the signal (using kill system call). Find out whether the first program is able to catch
                the signal or not.
Date: 17 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function for catching signals
void signal_handler() {
    // if (sig == SIGINT) {
    //     printf("Caught SIGINT (Ctrl+C)\n");
    // } else if (sig == SIGSTOP) {
    //     printf("Caught SIGTSTP (Ctrl+Z)\n");
    // } else {
    //     printf("Caught signal %d\n", sig);
    // }
    printf("Caught SIGTSTP (Ctrl+Z)\n");
}

int main() {
    // Set up signal handler for SIGINT and SIGTSTP (just as an example)
     // Catch Ctrl+C
    signal(SIGSTOP, signal_handler); // Catch Ctrl+Z
    
    // Inform the user
    printf("Waiting for signals (SIGSTOP cannot be caught)\n");
    
    // Infinite loop to keep the program running and waiting for signals
    while (1) {
        sleep(30);  // Wait for signals
    }

    return 0;
}

/*
============================================================================
Command line: cc 13a.c && ./a.out
Output: 
Parent process (PID: 5583) is running.
Child process (PID: 5584) created. Parent process PID: 5583
Child process is sending SIGKILL to parent (PID: 5583)
Killed
parv@parv-ASUS-TUF-Gaming-A15-FA506IH-FA506IH:~/Desktop/SS/labexercise/Hands On 2$ Child process (PID: 5584) is now an orphan, adopted by init/systemd (new parent PID: 2155)
============================================================================
*/

/* 
    A program cannot catch a SIGSTOP signal.We can conclude this by observing that the customHandler function is never executed and instead the program is terminated !
    Two signals that cannot be caught or ignored
    SIGSTOP
    SIGKILL
*/