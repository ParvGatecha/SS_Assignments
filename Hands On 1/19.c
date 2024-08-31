/*
Parv Ketanbhai Gatecha
MT2024108

19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

unsigned long long rdtsc()
{
    unsigned long long dst;
    __asm__ __volatile__("rdtsc": "=A"(dst));
    return dst;
}

void main()
{
    long long int start, end;
    start = rdtsc();
    printf("Process id: %d\n", getpid());
    end = rdtsc();
    printf("Difference is : %llu\n", end - start);
}
/*
Process id: 16258
Difference is : 99690
*/