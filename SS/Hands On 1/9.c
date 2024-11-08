/*
Parv Ketanbhai Gatecha
MT2024108

9. Write a program to print the following information about a given file.
*/

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {

    struct stat fileStat;

    if (stat(argv[1], &fileStat) == -1) {
        perror("Error getting file statistics");
        return 1;
    }

    printf("File: %s\n", argv[1]);
    printf("Inode: %lu\n", fileStat.st_ino);
    printf("Number of hard links: %lu\n", fileStat.st_nlink);
    printf("UID: %u\n", fileStat.st_uid);
    printf("GID: %u\n", fileStat.st_gid);
    printf("Size: %ld bytes\n", fileStat.st_size);
    printf("Block size: %ld bytes\n", fileStat.st_blksize);
    printf("Number of blocks: %ld\n", fileStat.st_blocks);
    printf("Time of last access: %s", ctime(&fileStat.st_atime));
    printf("Time of last modification: %s", ctime(&fileStat.st_mtime));
    printf("Time of last change: %s", ctime(&fileStat.st_ctime));

    return 0;
}

/*
File: 10txt.txt
Inode: 8019427
Number of hard links: 1
UID: 1000
GID: 1000
Size: 30 bytes
Block size: 4096 bytes
Number of blocks: 8
Time of last access: Thu Aug 22 09:13:02 2024
Time of last modification: Fri Aug  9 21:27:41 2024
Time of last change: Thu Aug 22 09:11:50 2024
*/