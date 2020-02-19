#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>


int main(void){

	ssize_t nr;
	unsigned long word;
	int fd=open("foo.txt",O_RDWR | O_APPEND | O_CREAT,0644);

	if (fd==-1)
		perror("Could not open file.");
		
	nr=read(fd, &word,sizeof(unsigned long));
	if (nr == -1)
		perror("Error");	
	else
		printf("Read Successfully! And the value of nr is %d\n",nr);

	// Printing the content of the file. 
	close(fd);
	fd=open("foo.txt",O_RDWR);

	char buf[100];
	if(read(fd,buf,100)==-1)
		perror("Read Error!");
	printf("Content of the file is :%s\n",buf);

	return 0;
}
