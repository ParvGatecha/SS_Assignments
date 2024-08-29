// Parv Ketanbhai Gatecha
// MT2024108

/*
1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
*/

#include <unistd.h>
#include <stdio.h>

int main() {
    int status = link("file", "sftlh");
    if (status == 0) {
        printf("Hard link created successfully.\n");
    } else {
        perror("link");
    }
    return 0;
}
