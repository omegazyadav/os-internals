#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdio.h>

#define errExit(msg) do { perror(msg); exit(EXIT_FAILURE); \
                    } while(0)

static int childFunc(void *arg)
{
    printf("childFunc(): PID = %ld\n",(long)getpid);
    printf("chldFunc(): PPID = %ld\n",(long)getppid());

    char *mount_point = arg;

    if (mount_point != NULL) {
        mkdir(mount_point,0555);
        if (mount("proc", mount_point, "proc", 0, NULL) == -1)
            errExit("mount");
        printf("Mounting procfs at %s\n",mount_point);
    }
    execlp("sleep","sleep","500",(char *)NULL);

    if (umount(mount_point) == -1)
            errExit("umount");
    if (rmdir(arg) == -1)
        errExit("rmdir");

    errExit("Success");
}

#define STACK_SIZE (1024 * 1024)

static char child_stack[STACK_SIZE];

int main(int argc, char *argv[]) 
{
    pid_t child_pid;
    child_pid = clone(childFunc,child_stack+STACK_SIZE,
                    CLONE_NEWPID | SIGCHLD, argv[1]);
    if (child_pid == -1)
        errExit("clone");

    printf("PID returned by clone(): %ld\n",(long)child_pid);

    if (waitpid(child_pid, NULL, 0) == -1)
        errExit("waitpid");

    exit(EXIT_SUCCESS);
}
