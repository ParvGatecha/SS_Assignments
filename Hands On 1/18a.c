/*
Parv Ketanbhai Gatecha
MT2024108

18. Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
*/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
typedef struct record
{
    int id;
    int ticket;
} record;

int main(int argc, char *argv[])
{
    record r1 = {1, 1};
    record r2 = {2, 2};
    record r3 = {3, 3};
    int fd = open(argv[1], O_WRONLY | O_CREAT, S_IRWXU);
    char buf[17];
    sprintf(buf, "id=%dticket_no=%d", r1.id, r1.ticket);
    write(fd, &buf, sizeof(buf));
    memset(&buf, 0, sizeof(buf));
    sprintf(buf, "id=%dticket_no=%d", r2.id, r2.ticket);
    write(fd, &buf, sizeof(buf));
    memset(&buf, 0, sizeof(buf));
    sprintf(buf, "id=%dticket_no=%d", r3.id, r3.ticket);
    write(fd, &buf, sizeof(buf));
    return 0;
}
