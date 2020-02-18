#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){

	int file_desc;
	file_desc=open("omega.txt",O_RDWR | O_APPEND | O_CREAT , 0644);
	
	if(file_desc==-1)
		printf("Error creating file. ");
//	close(0); Uncomment this and you will get 0 as desired file descriptor. Like dup() does. 

	int copy_desc=fcntl(file_desc,F_DUPFD,0);

	if (copy_desc==-1)
		printf("Error!\n");
	
	printf("The value of file descriptor are: %d %d",file_desc,copy_desc);

	return 0;
}
