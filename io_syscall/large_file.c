#define _LARGEFILE64_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "tlpi_hdr.h"


int main(int argc,char * argv[]){
	
	int fd;
	off64_t off;

	if(argc!=3 || strcmp(argv[1],"--help")==0)
		usageErr("%s pathname offset \n",argv[0]);

	fd=open64(argv[1],O_CREAT | O_RDWR ,0644);
	if(fd==-1)
		errExit("Error!");
	off=atoll(argv[2]);
	if(lseek(fd,off,SEEK_SET)==-1)
		errExit("lseek!");

	if(write(fd,"hello omega",20)==-1)
		perror("Write!");
	return 0;
}
