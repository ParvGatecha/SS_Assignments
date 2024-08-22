#include <fcntl.h>   // for open(), fcntl(), O_* flags
#include <unistd.h>  // for close()
#include <stdio.h>   // for printf(), perror()
#include <stdlib.h>  // for exit()

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the file
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Get the file status flags using fcntl()
    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("Error getting file flags");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Extract the access mode from the flags
    int accessMode = flags & O_ACCMODE;

    // Determine the file opening mode
    switch (accessMode) {
        case O_RDONLY:
            printf("File is opened in read-only mode.\n");
            break;
        case O_WRONLY:
            printf("File is opened in write-only mode.\n");
            break;
        case O_RDWR:
            printf("File is opened in read-write mode.\n");
            break;
        default:
            printf("Unknown file opening mode.\n");
    }

    // Close the file
    close(fd);

    return 0;
}
