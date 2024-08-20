#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(int argc,char *argv[])
{
	int o=open(argv[1],O_RDWR);
	printf("%d \n",o);
	int e=open(argv[1],O_EXCL);
	printf("%d \n",e);
}
