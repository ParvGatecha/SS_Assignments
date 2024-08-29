/*
Parv Ketanbhai Gatecha
MT2024108

3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call
*/

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(){
	int fd = creat("3txt.txt",S_IRUSR | S_IWUSR);

	if(fd == -1){
		perror("Error creating file");
		return 1;
	}

	printf("File descriptor value for 3txt.txt: %d",fd);
	printf("\n");

	close(fd);

	return 0;
}
