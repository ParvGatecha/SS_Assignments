#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fds[5];
    char filename[20];

    for (int i = 0; i < 5; i++) {
        sprintf(filename, "%dtxt.txt", i+1);
        fds[i] = open(filename, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
        
        if (fds[i] == -1) {
            perror("Error creating file");
            return 1;
        } else {
            printf("File descriptor for '%s': %d\n", filename, fds[i]);
        }
    }

    while (1) {
        sleep(1);  
    }

    for (int i = 0; i < 5; i++) {
        close(fds[i]);
    }

    return 0;
}
