/*
Parv Ketanbhai Gatecha
MT2024108

6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
*/

#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];
    ssize_t b;

    while ((b = read(0, buffer, BUFFER_SIZE)) > 0) {
        if (write(1, buffer, b) != b) {
            perror("Error writing to STDOUT");
            return 1;
        }
    }

    if (b == -1) {
        perror("Error reading from STDIN");
        return 1;
    }

    return 0;
}
