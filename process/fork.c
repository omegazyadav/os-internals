#include <stdio.h>
#include <unistd.h>

static int idata=111;				/* Allocated data segment */

int main(int argc, char *argv[])
{
	int istack=222;
	pid_t childPid;

	switch(childPid=fork()){
		case -1:
			printf("Fork Error!\n");
			break;
		case 0:
			idata*=3;
			istack*=3;
			break;
		default:
			sleep(3);
			break;
	}

	printf("PID=%ld %s idata=%d istack=%d\n",(long)getpid(),(childPid==0)?"(Child)":"(Parent)",idata,istack);
	return 0;
}
