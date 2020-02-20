#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define _GNU_SOURCE

int main(int argc, char *argv[]){

	int file_desc;
	file_desc=open("omega.txt",O_RDWR|O_APPEND|O_CREAT,0644);
	if(file_desc==-1)
		printf("Open failed!");

	int copy_desc=dup3(file_desc,4,FD_CLOEXEC);
	if(copy_desc==4)
		printf("Success!\n");
	else
		printf("Failed!\n");

	printf("The value of file_desc and copy_desc are %d %d\n",file_desc,copy_desc);
	return 0;
}
