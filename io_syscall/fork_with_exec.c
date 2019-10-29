/* Fork with execv syscall. */

/* First of all fork will create a child process and if pid==0 then invoke 
 * the execv syscall to execute the binary as specified. 
 */



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(void){

	pid_t pid;
	
	pid=fork();

	if (pid==-1)
		perror("fork");

	if (!pid){
		char *args[]={"vim", NULL};
		int ret;


		ret=execv("/bin/vim",args);

		if(ret==-1){
			perror("execv");
			exit (EXIT_FAILURE);
		}
	}
	return 0;
}
