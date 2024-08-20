#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    const char *fn = "10txt.txt";
    int fd = open(fn, O_RDWR | O_CREAT | O_TRUNC, 0644);
    

    char c[10] = "ABCDEFGHIJ";
	write(fd, c, 10);
	int s = lseek(fd, 10, SEEK_CUR);
	printf("%d\n", s);
	write(fd, c, 10);
	s = lseek(fd, 0, SEEK_CUR);
	printf("%d\n", s);

	return 0;
}
