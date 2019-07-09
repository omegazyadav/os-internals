#include "apue.h"

int globvar=6;
char buf[]="A write to stdout\n";

int main(void)
{
    int var;
    pid_t pid;

    var=88;
    if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
        err_sys("Write error");
    printf("Before fork()\n");

    if((pid=fork())<0){
        err_sys("Fork error");
    }
    else if(pid==0)
    {
        globvar++;
        var++;
    }
    else
    {
        sleep(20);
    }
    printf("PID=%ld,glob=%d,var=%d\n",(long)getpid(),globvar,var);
    exit(0);
        

    
}
