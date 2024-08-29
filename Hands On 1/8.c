/*
Parv Ketanbhai Gatecha
MT2024108

8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    

    int fd = open(argv[1], O_RDONLY);
    

    char buffer[BUFFER_SIZE];
    ssize_t b;
    char ch;
    int i = 0;

    while ((read(fd, &ch, 1)) > 0) {
        buffer[i++] = ch;
        if (ch == '\n' || i == BUFFER_SIZE - 1) {
            buffer[i] = '\0';
            printf("%s", buffer);
            i = 0;
        }
    }

    close(fd);
    return 0;
}
