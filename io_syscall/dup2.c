#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(void){
	

	/*
	 * open syscall with file permission specified.
	 */

	int file_desc=open("omega.txt", O_CREAT | O_WRONLY | O_RDONLY | O_APPEND , 0644);

	if(file_desc<0)
		printf("Error in opening the file."); 
	/*
	 * The syntax for dup2 is dup2(int Old_fd, int new_fd) which takes the old file descriptor and create another user defined file descriptor
	 */

	int copy_desc=dup2(file_desc,4);

	printf("The value of file descriptor are %d %d \n ",file_desc,copy_desc);



	write(file_desc, "omega\n", 6);
	write(copy_desc, "omegazyadav\n", 11);
	
	return 0;
}

