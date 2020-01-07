#include <stdio.h>
#include <fcntl.h>
#include <errno.h>


int main(void){
	int fd=open("hello.txt",O_RDONLY | O_CREAT,0644 );

	printf("fd=%d\n",fd);

	if (fd==-1){
		perror("Program");
		
	}else{
		printf("File opened successfully!\n");
	}
	return 0;
}
