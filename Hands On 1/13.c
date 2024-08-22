#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set readfds;  // File descriptor set
    struct timeval timeout;  // Timeout structure

    // Initialize the file descriptor set
    FD_ZERO(&readfds);       // Clear all entries from the set
    FD_SET(STDIN_FILENO, &readfds);  // Add STDIN (fd 0) to the set

    // Set timeout value to 10 seconds
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    // Call select() to wait for input on STDIN for up to 10 seconds
    int result = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (result == -1) {
        perror("select() error");
        return 1;
    } else if (result == 0) {
        printf("No data was entered within 10 seconds. Timeout occurred.\n");
    } else {
        // Data is available to read
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            char buffer[1024];
            ssize_t bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
            if (bytesRead > 0) {
                buffer[bytesRead] = '\0';  // Null-terminate the string
                printf("Data received: %s\n", buffer);
            }
        }
    }

    return 0;
}
