/*
============================================================================
Name : 30b.c
Author : Parv Gatecha (MT2024108)
Description : Write a program to create a shared memory.
                a. write some data to the shared memory
                b. attach with O_RDONLY and check whether you are able to overwrite.
                c. detach the shared memory
                d. remove the shared memory
Date: 17 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
int main()
{
    key_t key = 12345;
    // shared memory created
    int shmid = shmget(key, 1024, IPC_CREAT | 0744);
    // attach shared memory to process address space
    char *data;
    data = shmat(shmid, (void *)0, SHM_RDONLY);
    if (data == (void *)-1)
    {
        perror("Shared memory not attach");
        return 1;
    }

    printf("write in shared memory\n");
    scanf("%[^\n]", data);
}
/*
============================================================================
Command line: cc 30b.c && ./a.out
Output: 
write in shared memory
f
Segmentation fault (core dumped)
============================================================================
*/