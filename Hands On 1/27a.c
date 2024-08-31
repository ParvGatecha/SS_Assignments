/*
Parv Ketanbhai Gatecha
MT2024108

/*
write a program to execute ls -Rl by the following system calls
a. execl
*/

#include <stdio.h>
#include <unistd.h>
int main()
{
    char *path = "/bin/ls";
    execl(path, path, "-Rl", NULL);
    return 0;
}
/*
.:
total 272
-rw-rw-r-- 1 parv parv   799 Aug 30 10:12 10.c
-rw-r--r-- 1 parv parv    30 Aug  9 21:27 10txt.txt
-rw-rw-r-- 1 parv parv   899 Aug 30 13:35 11.c
-rw-r--r-- 1 parv parv    64 Aug  9 21:43 11txt.txt
-rw-rw-r-- 1 parv parv   700 Aug 30 13:35 12.c
-rw-rw-r-- 1 parv parv   685 Aug 30 13:36 13.c
-rw-rw-r-- 1 parv parv  1069 Aug 30 13:37 14.c
-rw-rw-r-- 1 parv parv  3852 Aug 30 13:37 15.c
-rw-rw-r-- 1 parv parv  1728 Aug 30 13:38 16a.c
-rw-rw-r-- 1 parv parv  1698 Aug 30 13:38 16b.c
-rw-rw-r-- 1 parv parv   661 Aug 30 13:40 17a.c
-rw-rw-r-- 1 parv parv   871 Aug 30 13:43 17b.c
-rwx------ 1 parv parv     2 Aug 20 10:16 17_ticket.txt
-rwx------ 1 parv parv     2 Aug 30 13:41 17txt.txt
-rw-rw-r-- 1 parv parv   991 Aug 30 13:46 18a.c
-rw-rw-r-- 1 parv parv   921 Aug 30 13:49 18b.c
-rw-rw-r-- 1 parv parv  1413 Aug 30 13:52 18c.c
-rwx------ 1 parv parv    51 Aug 30 13:52 18txt.txt
-rw-rw-r-- 1 parv parv   547 Aug 30 13:54 19.c
-rw-rw-r-- 1 parv parv    77 Aug  8 08:52 1a
-rw-rw-r-- 1 parv parv   326 Aug 22 09:14 1a.c
-rw-rw-r-- 1 parv parv   516 Aug 30 10:02 1b.c
-rw-rw-r-- 1 parv parv   568 Aug 30 10:02 1c.c
-rw------- 1 parv parv     0 Aug  9 11:13 1txt.txt
-rwxrwxr-x 1 parv parv 16000 Aug 20 15:00 2
-rw-rw-r-- 1 parv parv   806 Aug 30 13:54 20.c
-rw-rw-r-- 1 parv parv   387 Aug 30 14:13 21.c
-rw-rw-r-- 1 parv parv   519 Aug 29 08:22 22.c
-rwx------ 1 parv parv    54 Aug 30 14:18 22txt.txt
-rw-rw-r-- 1 parv parv  1077 Aug 30 14:21 23.c
-rw-rw-r-- 1 parv parv   970 Aug 30 14:23 24.c
-rwxrwxr-x 1 parv parv 16032 Aug 31 10:04 25
-rw-rw-r-- 1 parv parv  1571 Aug 31 10:03 25.c
-rw-rw-r-- 1 parv parv   247 Aug 29 08:24 26a.c
-rw-rw-r-- 1 parv parv   343 Aug 29 08:24 26b.c
-rw-rw-r-- 1 parv parv   249 Aug 29 08:25 27a.c
-rw-rw-r-- 1 parv parv   385 Aug 29 08:25 27b.c
-rw-rw-r-- 1 parv parv   349 Aug 29 08:25 27c.c
-rw-rw-r-- 1 parv parv   276 Aug 29 08:25 27d.c
-rw-rw-r-- 1 parv parv   412 Aug 29 08:26 27e.c
-rw-rw-r-- 1 parv parv   706 Aug 29 08:26 28.c
-rw-rw-r-- 1 parv parv  2109 Aug 29 08:26 29.c
-rw-rw-r-- 1 parv parv   362 Aug 22 09:16 2.c
-rw------- 1 parv parv     0 Aug  9 11:13 2txt.txt
-rwxrwxr-x 1 parv parv 16128 Aug 20 15:00 3
-rw-rw-r-- 1 parv parv  1025 Aug 30 10:00 30.c
-rw-rw-r-- 1 parv parv   460 Aug 30 10:03 3.c
-rw------- 1 parv parv     0 Aug 30 10:03 3txt.txt
-rw-rw-r-- 1 parv parv   329 Aug 30 10:04 4.c
-rw------- 1 parv parv     0 Aug  9 11:13 4txt.txt
-rw-rw-r-- 1 parv parv   965 Aug 30 10:05 5.c
-rw------- 1 parv parv     0 Aug  9 11:13 5txt.txt
-rw-rw-r-- 1 parv parv   572 Aug 30 10:06 6.c
-rw-rw-r-- 1 parv parv   459 Aug 30 10:06 7.c
-rw-rw-r-- 1 parv parv   703 Aug 30 10:07 8.c
-rw-rw-r-- 1 parv parv  1418 Aug 30 10:07 9.c
-rwxrwxr-x 1 parv parv 15952 Aug 31 10:05 a.out
-rw-rw-r-- 2 parv parv     0 Aug  8 08:53 file
-rwxrwxr-x 1 parv parv 16000 Aug 20 15:07 infinite
-rwxr--r-- 1 parv parv     0 Aug  8 09:20 newfile.txt
-rw-rw-r-- 1 parv parv     0 Aug 14 18:37 README.md
lrwxrwxrwx 1 parv parv     4 Aug  8 09:01 sftl -> file
lrwxrwxrwx 1 parv parv     4 Aug  9 10:06 sftlf -> file
-rw-rw-r-- 2 parv parv     0 Aug  8 08:53 sftlh
*/