#include <fcntl.h>   // for open(), O_*, fcntl()
#include <unistd.h>  // for dup(), dup2(), write(), close()
#include <stdio.h>   // for perror(), printf()

int main() {
    const char *filename = "11txt.txt";
    int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // 1. Duplicate using dup()
    int fd_dup = dup(fd);
    if (fd_dup == -1) {
        perror("Error duplicating file descriptor with dup");
        close(fd);
        return 1;
    }

    // 2. Duplicate using dup2()
    int fd_dup2 = dup2(fd, fd_dup + 1);
    if (fd_dup2 == -1) {
        perror("Error duplicating file descriptor with dup2");
        close(fd);
        close(fd_dup);
        return 1;
    }

    // 3. Duplicate using fcntl()
    int fd_fcntl = fcntl(fd, F_DUPFD, fd_dup2 + 1);
    if (fd_fcntl == -1) {
        perror("Error duplicating file descriptor with fcntl");
        close(fd);
        close(fd_dup);
        close(fd_dup2);
        return 1;
    }

    // Write to the file using original descriptor
    const char *text1 = "Original FD write.\n";
    if (write(fd, text1, 19) != 19) {
        perror("Error writing with original FD");
    }

    // Write to the file using dup() descriptor
    const char *text2 = "dup FD write.\n";
    if (write(fd_dup, text2, 14) != 14) {
        perror("Error writing with dup FD");
    }

    // Write to the file using dup2() descriptor
    const char *text3 = "dup2 FD write.\n";
    if (write(fd_dup2, text3, 15) != 15) {
        perror("Error writing with dup2 FD");
    }

    // Write to the file using fcntl() descriptor
    const char *text4 = "fcntl FD write.\n";
    if (write(fd_fcntl, text4, 16) != 16) {
        perror("Error writing with fcntl FD");
    }

    // Close all file descriptors
    close(fd);
    close(fd_dup);
    close(fd_dup2);
    close(fd_fcntl);

    return 0;
}
