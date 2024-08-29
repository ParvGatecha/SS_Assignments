/*
Parv Ketanbhai Gatecha
MT2024108

21. Write a program, call fork and print the parent and child process id.
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
int main()
{
    printf("parent process id = %d\n", getpid());
    int cid = fork();
    if(cid) printf("child process id = %d\n", cid);
    return 0;
}
