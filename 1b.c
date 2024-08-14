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
