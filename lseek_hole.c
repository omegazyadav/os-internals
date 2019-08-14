#include "apue.h"
#include<fcntl.h>

char buf1[]="abcdefghij";
char buf2[]="ABCDEFGHIJ";

int main()
{
    int fd; /* file descriptor*/
    if ((fd=creat("file.hole",FILE_MODE))<0)
        err_sys("creat system call error");

    if (write(fd,buf1,10)!=10)
        err_sys("buf1 write error");
    /*offset now =10*/

    if (lseek(fd,16394,SEEK_SET)==-1)
        err_sys("lseek error");
    /*offset now=16394*/

    if (write(fd,buf2,10)!=10)
        err_sys("buf2 write error");
    /*offset now =16404*/
    
    exit(0);
}
