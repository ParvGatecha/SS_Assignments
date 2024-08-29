/*
Parv Ketanbhai Gatecha
MT2024108

12. Write a program to find out the opening mode of a file. Use fcntl.
*/
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argv, char *argc[])
{
    int fd = open(argc[1], O_RDONLY);

    int fmode = fcntl(fd, F_GETFL);
    printf("%d\n", fmode);
    int accessMode = fmode & O_ACCMODE;
    printf("%d\n", accessMode);
    switch (accessMode)
    {
    case O_RDWR:
        printf("O_RDWR");
        break;
    case O_WRONLY:
        printf("O_WRONLY");
        break;
    case O_RDONLY:
        printf("O_RDONLY");
        break;
    default:
        break;
    }
    return 0;
}