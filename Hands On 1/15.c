#include <stdio.h>

extern char **environ; 
int main() {
    char **env = environ;

    // Iterate through the environment variables and print each one
    while (*env) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}
