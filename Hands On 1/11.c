/*
Parv Ketanbhai Gatecha
MT2024108

11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
*/
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argv,char *argc[]){
	int fd=open(argc[1],O_WRONLY|O_APPEND|O_CREAT,S_IRWXU);
	int d1=dup(fd);//assigne next minimun file descriptor
	write(fd,"Hi, written using original file descriptor\n",45);
	write(d1,"Hi, USER Written using dup() file descriptor\n",47);
	int d2=dup2(fd,10);// if 10 file descriptor is avalible than assign otherwise return -1
	write(d2,"Hi, USER written using dup2() file descriptor\n",48);
	int d3 = fcntl(fd, F_DUPFD, 5);//assigne fd greater than or equal to 5 
	write(d3,"Hi, USER written using fcntl() file descriptor\n",49);
	return 0;

}