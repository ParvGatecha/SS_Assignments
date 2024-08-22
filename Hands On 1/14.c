#include <stdio.h>
#include <sys/stat.h>   // for stat() and struct stat
#include <stdlib.h>     // for exit()
#include <unistd.h>     // for lstat()

void print_file_type(const struct stat *fileStat) {
    if (S_ISREG(fileStat->st_mode)) {
        printf("This is a regular file.\n");
    } else if (S_ISDIR(fileStat->st_mode)) {
        printf("This is a directory.\n");
    } else if (S_ISLNK(fileStat->st_mode)) {
        printf("This is a symbolic link.\n");
    } else if (S_ISCHR(fileStat->st_mode)) {
        printf("This is a character device.\n");
    } else if (S_ISBLK(fileStat->st_mode)) {
        printf("This is a block device.\n");
    } else if (S_ISFIFO(fileStat->st_mode)) {
        printf("This is a FIFO (named pipe).\n");
    } else if (S_ISSOCK(fileStat->st_mode)) {
        printf("This is a socket.\n");
    } else {
        printf("Unknown file type.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct stat fileStat;

    // Get file statistics using lstat() to handle symbolic links properly
    if (lstat(argv[1], &fileStat) == -1) {
        perror("Error determining file type");
        exit(EXIT_FAILURE);
    }

    // Print file type
    print_file_type(&fileStat);

    return 0;
}
