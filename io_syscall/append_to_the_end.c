#include <fcntl.h>
#include "tlpi_hdr.h"

int main(void){
	const char *buf="Append this in the end of the file. ";
	int fd=open("hello.txt",O_RDWR | O_CREAT, 0644);

	printf("fd=%d\n",fd);

	if (fd==-1){
		perror("Program");
		
	}else{
		printf("File opened successfully!\n");
	}


	if(lseek(fd,0,SEEK_END==-1))
		errExit("Lseek error!");
	if(write(fd,buf,strlen(buf))!=strlen(buf))
		errExit("Write error!");

	return 0;
}
