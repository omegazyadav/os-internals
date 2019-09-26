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
	 * This execv syscall takes full path of the binary program as a argument and replaces the current process from the 
	 * memory and loads it into the current address space. 
	 */

	ret=execv("/bin/vim",args);
	
	if(ret==-1)
		printf("Execv call error:\n\n");

	return 0;
}
