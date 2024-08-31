// Pipariya Darshitkumar
// MT2022035

/*
Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
*/

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <errno.h>

// Function to print the current scheduling policy
void print_sched_policy(int policy) {
    switch (policy) {
        case SCHED_OTHER:
            printf("Current scheduling policy: SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("Current scheduling policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current scheduling policy: SCHED_RR\n");
            break;
        default:
            printf("Unknown scheduling policy\n");
    }
}

int main() {
    int policy;
    struct sched_param param;
    int userInput;

    // Get the current scheduling policy
    policy = sched_getscheduler(0); // 0 means the calling process
    if (policy == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }

    print_sched_policy(policy);

    // Get the desired scheduling policy from the user
    printf("Enter the desired scheduling policy:\n");
    printf("1 for SCHED_FIFO\n");
    printf("2 for SCHED_RR\n");
    printf("3 for SCHED_OTHER\n");
    scanf("%d", &userInput);

    // Use switch to determine the desired policy
    switch (userInput) {
        case 1:
            policy = SCHED_FIFO;
            break;
        case 2:
            policy = SCHED_RR;
            break;
        case 3:
            policy = SCHED_OTHER;
            break;
        default:
            fprintf(stderr, "Invalid input. Please enter 1, 2, or 3.\n");
            exit(EXIT_FAILURE);
    }

    // Set the priority for the scheduling policy
    param.sched_priority = sched_get_priority_max(policy);
    if (policy == SCHED_OTHER) {
        param.sched_priority = 0; // SCHED_OTHER does not use priority
    } else if (param.sched_priority == -1) {
        perror("sched_get_priority_max");
        exit(EXIT_FAILURE);
    }

    // Set the new scheduling policy
    if (sched_setscheduler(0, policy, &param) == -1) {
        perror("sched_setscheduler");
        exit(EXIT_FAILURE);
    }

    printf("Scheduling policy changed successfully.\n");

    // Verify the new scheduling policy
    policy = sched_getscheduler(0);
    if (policy == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }

    print_sched_policy(policy);

    return 0;
}

/*
Current scheduling policy: SCHED_OTHER
Enter the desired scheduling policy:
1 for SCHED_FIFO
2 for SCHED_RR
3 for SCHED_OTHER
1
Scheduling policy changed successfully.
Current scheduling policy: SCHED_FIFO
*/