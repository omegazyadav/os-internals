// flag O_EXCL works opposite to what O_CREAT does. If the intended file is not found then it raise the error instead of creating it. 
// This flag set the raised error to EEXIT. 

#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char *args[])
{
	int fd;
	fd=open("foo.txt",O_RDONLY, O_EXCL);

	if(fd==-1){
		perror("Error!:");
	}

	return 0;
}
