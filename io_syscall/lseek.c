#include <fcntl.h>
#include <sys/types.h>
#include "tlpi_hdr.h"

int main(void) 
{
	char buf[]="omega zyadav";
	int fd;
	fd=open("file.txt",O_CREAT | O_RDWR,0644);
	if(fd==-1){
		errExit("Open Error:");

	}
	if(write(fd,buf,strlen(buf))==-1){
		errExit("Write Error!");
	}

	if(lseek(fd,100,SEEK_END)==-1){
		errExit("Seek Error!");
	}


}
