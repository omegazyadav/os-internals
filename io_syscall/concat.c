#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int ret,i;
    char *filecopy(int);
    char buffer[100] ;
    for(int i=1;i<3;i++)
    if ((ret=open(argv[i],O_RDONLY,O_APPEND))==-1) {
         printf("cat: can't open %s\n",argv[i]);
         goto err;
    } else {
        filecopy(ret);
        close(ret);
      }
    
    return 0;

err:
    return -1;
}

char *filecopy(int ret)
{
    int c;
   while(read(ret,&c,1))
       write(STDOUT_FILENO,&c,1);

}

