#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    int status = mknod("file", S_IFIFO | 0666, 0);
    if (status == 0) {
        printf("FIFO created successfully.\n");
    } else {
        perror("mknod");
    }
    return 0;
}
