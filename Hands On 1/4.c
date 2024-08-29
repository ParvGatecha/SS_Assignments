/*
Parv Ketanbhai Gatecha
MT2024108

4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.
*/

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
