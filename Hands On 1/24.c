/*
Parv Ketanbhai Gatecha
MT2024108

24. Write a program to create an orphan process.
*/

#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
int main(){
    int pid;
    pid=fork();
    if(pid==0){
        // inside child process as pid will be 0.
        //sleep child untill parent finish its execution.
        sleep(30);
        printf("inside child pid= %d\n", getpid());
        printf("parent id= %d\n", getppid()); // as parent terminated we can't get parent id in child process so we will get different value;
    }else{
        // inside parent
        sleep(10);//this sleep is just for cheking pid using ps command while execution of program
        printf("inside parent pid= %d\n", getpid());
        printf("child pid= %d\n", pid);
    }
    return 0;
}
