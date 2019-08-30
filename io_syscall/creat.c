#include <stdio.h>
#include <fcntl.h>
#include <errno.h>


int main(void){

	//Creat syscall only takes pathname for the file and mode of operation. 
	//This syscall is identical to open(const char *pathname, int flags( O_WRONLY | O_CREAT | O_TRUNC ), mode_t mode). 

	int fd=creat("foo.txt", 0644);

	printf("fd=%d\n",fd);

	if (fd == -1){
		perror("Program");
		
	}
	return 0;
}
