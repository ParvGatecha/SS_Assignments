/*
Parv Ketanbhai Gatecha
MT2024108

17. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
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

/*
5
Enter ticket number:	ticket number is stored in file
*/
