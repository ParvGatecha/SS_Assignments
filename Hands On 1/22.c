/*
Parv Ketanbhai Gatecha
MT2024108

22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{

    fork();
    int fd = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);
    char buf[27];
    sprintf(buf, "written by process %d \n", getpid());
    write(fd, &buf, sizeof(buf));
}
