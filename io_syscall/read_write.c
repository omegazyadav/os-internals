#include <fcntl.h>
#include "tlpi_hdr.h"

#define SIZE 100
char buffer[SIZE];

int main(void)
{	

	char *buf="omega zyadav is my name. \n";
	int fd;
	fd=open("foo.txt",O_RDWR | O_APPEND | O_CREAT | O_SYNC ,0644);

	
	ssize_t byte_write=write(fd,buf,strlen(buf));
	if (byte_write==-1)
		errExit("Error in write. \n");

	printf("The size of the byte is :%d\n",byte_write);
	close(fd);


	fd=open("foo.txt",O_RDWR | O_APPEND | O_CREAT | O_SYNC ,0644);


	ssize_t byte_read=read(fd,buffer,SIZE);
	if(byte_read==-1)
		errExit("Error on read!\n");

	printf("The size of the byte is :%d\n",byte_read);

	printf("The content written is :%s\n",buffer);



	if(close(fd)==-1) /* What if the file descriptor is not opened at all :) */
		errExit("Closing the fd error!"); 

	return 0;
}
