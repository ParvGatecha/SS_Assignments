/*
============================================================================
Name : 27a.c
Author : Parv Gatecha (MT2024108)
Description : Write a program to receive messages from the message queue.
                a. with 0 as a flag
                b. with IPC_NOWAIT as a flag
Date: 17 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct msg_buffer
{
    /* data */
    long msg_type;
    char msg_text[100];
} msg_buffer;
int main()
{
    msg_buffer message;
    // generate unique no
    key_t key = 1234; // projext path is current directory and project id=1
    // create massage queue using msgget
    //  msgget creates a message queue
    //  and returns identifier
    int msgid = msgget(key, 0666 | IPC_CREAT);
    printf("enter msgtype:\n");
    scanf("%ld", &message.msg_type);
    int size_s = msgrcv(msgid, &message, sizeof(message), message.msg_type, IPC_NOWAIT); // 0 flag will wait for msg and give us warning if message of type is not in msg queue.
    if (size_s <= 0)
    {
        perror("No message in queue\n");
    }
    else
    {
        printf("Message: %s\n", message.msg_text);
    }
    return 0;
}
/*
============================================================================
Command line: cc 27a.c && ./a.out
Output: 
enter msgtype:
1
Message: Message 2
============================================================================
*/