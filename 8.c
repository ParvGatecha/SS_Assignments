#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        perror("Usage: <filename>");
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t b;
    char ch;
    int i = 0;

    while ((b = read(fd, &ch, 1)) > 0) {
        buffer[i++] = ch;
        if (ch == '\n' || i == BUFFER_SIZE - 1) {
            buffer[i] = '\0';
            printf("%s", buffer);
            i = 0;
        }
    }

    if (b == -1) {
        perror("Error reading file");
    }

    close(fd);
    return 0;
}
