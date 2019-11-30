/* When you open the file with system call like open(),creat(), the operating system will assign the lowest 
*  number as a file discriptro. The standard file descriptor along with POSIX name and default file descriptor are:-
*
*			1. stdin  - STDIN_FILENO  - 0
*			2. stdout - STDOUT_FILENO - 1 
*			3. stderr - STDERR_FILENO - 2 
*
* Here I've closed the standard_input file descripor so that the STDIN_FILENO will be free so 
* open function can assign the availabe lowest FD to the file. 
*	
*/

 * #include <fcntl.h>
#include "tlpi_hdr.h"



int main(int argc, char *argv[]){

	if(close(STDIN_FILENO)==-1)
		errExit("close:\n");

	int fd;
	fd=open("foo.txt",O_RDONLY); 
	printf("The value of fd is :%d\n",fd); // The output of the FD should be 0. 

	if(fd==-1)
		errExit("Open :\n");
	return 0;
}
