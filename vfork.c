#include "apue.h"
int globvar=6;  /* external variable in initialized data */
int main(void)
{ 
    /* The difference between vfork and fork system call is that in fork a copy of parent process along with its memory space is
     * created and any changes in the child process doesnot affect the parent process or variables declared on it since child 
     * and parent process is executing in different memory space but in case of vfork a child porcess is initating a complete new
     * porcess rather than cloning of parent process like in fork and it runs in the address space of the parent process until it
     *  calls either exec or exit system call. So any changes made in the child process is directly affects in the parent process
     *  since child is residing in the parent address space. Pretty amazing huh! :) */

    int var;
    pid_t pid;
    var=88;
    printf("Before vfork\n"); /* without flushing stdio */
    if ((pid=vfork())<0){
      //  err_sys("Vfork error");
      printf("Error");
    }else if(pid==0){
        globvar++;
        var++;
        _exit(0);
    }
    /* parent continues here */

    printf("pid=%ld,glob=%d,var=%d\n",(long)getpid(),globvar,var);
    exit(0);
}
