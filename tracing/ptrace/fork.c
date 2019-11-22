#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
	pid_t pid;
	pid=fork();

	if (pid==0){
		ptrace(PTRACE_TRACEME,0,NULL,NULL);
		execl("/bin/ls","ls","/home",NULL);

	}
	else {
		printf("Child terminated successfully!\n");
	}

	return 0;
}
