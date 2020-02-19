#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main(int argc,char *argv[]){

	int fd;
	char buf[100]="omegazyadav";
	fd=open("omega.txt",O_CREAT|O_RDWR|O_APPEND, 0644);
	if(fd==-1)
		printf("Open error!\n");
	ssize_t wr;
	wr=pwrite(fd,buf,12,0);
	if(wr==-1)
		printf("Write error!\n");
	close(fd);
	
	char read_buf[100];
	fd=open("omega.txt",O_RDONLY);
	ssize_t rd;
	rd=pread(fd,read_buf,4,4);
	
	if(rd==-1)
		printf("Read error!");
	printf("The content of the file is:%s\n",read_buf);
	return 0;
}
