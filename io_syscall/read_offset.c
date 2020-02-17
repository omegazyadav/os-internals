#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	
	char buf[1000];
	int fd;
	off_t offset,fileoffset;
	fd=open(argv[1],O_RDWR);
	
	if(fd==-1){
		printf("File read error");
	}

	offset=lseek(fd,0,SEEK_END);
	fileoffset=offset-50;
	lseek(fd,fileoffset,SEEK_SET);
	
	read(fd,buf,fileoffset);
	

	printf("The last 50 bytes of the file is :%s\n",buf);
	close(fd);

	return 0;
}
