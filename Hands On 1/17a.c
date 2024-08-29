/*
Parv Ketanbhai Gatecha
MT2024108

16. Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
    printf("Enter ticket number:\t");
    int fd = open(argv[1], O_RDWR | O_CREAT, S_IRWXU);
    if (fd == -1)
    {
        perror("Error while opening file!");
        return 0;
    }
    char *buf[10];
    int n = read(0, buf, 10);
    write(fd, buf, n);
    printf("ticket number is stored in file\n");
    return 0;
}
