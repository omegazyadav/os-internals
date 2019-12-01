#include <fcntl.h>
#include "tlpi_hdr.h"

#define SIZE 100

char buffer[SIZE];

int main(void)
{	
	char *buf="omega zyadav is my name. \n";
	int fd;
	fd=open("foo.txt",O_RDWR | O_APPEND | O_CREAT,0644);
	
	ssize_t byte_read=read(fd,buffer,SIZE);
	if(byte_read==-1)
		errExit("Error on read!\n");

	printf("The size of the byte is :%d\n",byte_read);

	printf("The content of the buffer is :%s\n",buffer);

	ssize_t byte_write=write(fd,buf,strlen(buf));
	if (byte_write==-1)
		errExit("Error in write. \n");

	printf("The size of the byte is :%d\n",byte_write);

	close(fd);

	return 0;
}
