#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc,char *argv[]){
	int fd1=open(argv[1],O_RDONLY);
	
	int fd2=open(argv[2],O_WRONLY|O_CREAT,S_IRWXU);
	
	char c;  
	while(read(fd1,&c,1)){
		write(fd2,&c,1);
	}
	printf("file copied");
	close(fd1);
	close(fd2);
	return 0;
}