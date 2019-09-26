#include <stdio.h>
#include <unistd.h>


int main(void){

	int ret;

	ret=execl("/bin/vim","vi","/home/omega/Documents/Linux System Programming/io_syscall/omega.txt",NULL);

	if(ret==-1)
		printf("Execl call error:\n\n");

	return 0;
}
