#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>


int main(void){
	int fd=open("foo.txt",O_WRONLY | O_CREAT | O_APPEND,0644);
	printf("fd=%d\n",fd);

	if (fd==-1){
		perror("Program");
		
	}

	if (close(fd) < 0){
		perror("Close:");
}
	printf("Closed the file descripter.\n");

	return 0;
}
