/* truncate() syscall. 
 * Whatever the offset of the file is, truncate syscall will eleminate the extra byte from the inode of the file. 
 *
 */ 


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(){
	char buf[100];
	int fd;
	fd=open("./test.txt", O_RDWR|O_SYNC);
	if (fd==-1)
		perror("Open:");

	int ret;
	ret=truncate("./test.txt",15);
	if (ret==-1)
		perror("Truncate:");

	ssize_t rd;
	rd=read(fd,buf,sizeof(buf));
	if(rd==-1)
		perror("Read:");

	printf("The content of the file is :%s\n",buf);
	const char *content="This is a pandamic situation. ";

	ssize_t wr;
	printf("%d\n\n",sizeof(&content));
	wr=write(fd,content,sizeof(content));
	if(wr==-1)
		perror("Write:");

	close(fd);

	return 0;
}

