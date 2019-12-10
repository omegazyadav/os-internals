#include <fcntl.h>
#include "tlpi_hdr.h"


int main(void)
{
	int fd;
	fd=open("hello.txt",O_RDWR | O_APPEND | O_CREAT, 0644);
	if(fd==-1)
		errExit("Open error. \n");
	
	int flag;
	flag=fcntl(fd,F_GETFL);
	if(flag==-1)
		errExit("Fcntl error! \n");
	return 0;
}
