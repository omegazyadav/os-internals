#include <stdio.h>
#include <unistd.h>




int main(void){
	
	/*
	 * This is the argument assigned to array character type pointer 
	 * which is passed to respective syscall as per /usr/include/unistd.h header file.
	 */

	char *args[]={"vim","/home/omega/omega.txt",NULL};

	int ret;
	/*
	 * This syscall specifies just a filename and it search on user's path to find out the binary files. 
	 */	
	ret=execlp("vim",args);

	if(ret==-1)
		printf("Execvp call error:\n\n");

	return 0;
}
