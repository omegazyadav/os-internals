#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>


int main(void){

	ssize_t nr;
	unsigned long word;
	int fd=open("foo.txt",O_WRONLY | O_APPEND,0644);
	printf("fd=%d\n",fd);

	if (fd==-1){
		perror("Program");
		
	}
	nr=read(fd, &word,sizeof(unsigned long));
	if (fd == -1){
		//printf("Error in reading file:");
		perror("Error:");
	}
	else
		printf("Read Successfully! And the value of nr is %d",nr);
	return 0;
}
