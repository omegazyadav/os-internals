#include <stdio.h>
#include <fcntl.h>
#include <errno.h>


int main(void){
	int fd=open("foo.txt",O_WRONLY | O_CREAT | O_APPEND);
	printf("fd=%d\n",fd);

	if (fd==-1){
		perror("Program");
		
	}
	return 0;
}
