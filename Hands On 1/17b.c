/*
Parv Ketanbhai Gatecha
MT2024108

16. Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int fd = open("~/Desktop/SS/labexercise/17_ticket.txt", O_RDWR);
    struct flock l = {F_WRLCK, SEEK_SET, 0, 0, 0};
    fcntl(fd, F_SETLKW, &l);
    printf("File is locked\n");

    char buf[100];
    
    int n = read(fd, &buf, 10);

    int buf_int = atoi(buf);
    buf_int += 1;
    sprintf(buf, "%d", buf_int);
    
    lseek(fd,0,SEEK_SET);
    write(fd, &buf, strlen(buf));
    printf("%d\t \n", buf_int);
    
    getchar();
    l.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &l);
    printf("file is unlocked\n");
    return 0;
}
