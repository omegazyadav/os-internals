#include <stdio.h>
#include <fcntl.h>
#include <errno.h>


int main(void){
	int fd=open("foo", O_CREAT | O_WRONLY | O_TRUNC , 0644 );
	printf("fd=%d\n",fd);

	if (fd==-1){
		perror("Program");
		
	}
	return 0;
}
