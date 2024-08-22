#include<stdio.h>
#include<unistd.h>
int main(){
	while(1){
		printf("Running in infinite loop...\n");
		sleep(1);
	}
	return 0;
}
