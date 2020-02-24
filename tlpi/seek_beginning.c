/* This is a exercise given in the book ``` The Linux Programming Interface ``` by Michael Kririsk. 
 * Problem Statement: To read the existing file and seek to the beginning of the file and begin writing in the file with some content. 
 * -> Well, Although we seek the beginning of the file for writing but file descriptor is opened with O_APPEND mode which means write 
 *  operation occurs at the end of the file no matter what the seek position currently is or set to whatsoever. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[]){

	int fd;
	char buf[]="Hello, World!\n";
	ssize_t buffer;
	fd=open("omega.txt",O_RDWR | O_APPEND | O_CREAT, 0644);
	if(fd==-1)
		perror("Error!");

	// Bringing the offset of the file at the beginning. 
	
	if(lseek(fd,0,SEEK_SET)==-1)
		perror("Seek Error!\n");
	

	if(write(fd,buf,sizeof(buf))==-1)
		perror("Write Error!\n");

	close(fd);

	fd=open("omega.txt",O_RDONLY);
	buffer=read(fd,buf,sizeof(buf));
	if(buffer==-1)
		perror("Read Error!");

	printf("The size of the bytes read is :%d \n",buffer);
	printf("The content of the file is :%s\n",buf);

	return 0;


}
