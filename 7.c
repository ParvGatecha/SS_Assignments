#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc,char *argv[]){
	int fd1=open(argv[1],O_RDONLY);
	if(fd1==-1){
		printf("Error while opening source file");
		close(fd1);
	}
	int fd2=open(argv[2],O_WRONLY|O_CREAT,S_IRWXU);
	if(fd2==-1){
		printf("Error while opening or creating destination file");
		close(fd2);
	}
	char c;  
	while(read(fd1,&c,1)){
		write(fd2,&c,1);
	}
	printf("file copied");
	close(fd1);
	close(fd2);
	return 0;
}