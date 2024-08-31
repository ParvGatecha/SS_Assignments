/*
Parv Ketanbhai Gatecha
MT2024108

10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
*/

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

/*
0000000   1   2   3   4   5   6   7   8   9   0  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   a   b   c   d   e   f   g   h   i   j
0000036
*/