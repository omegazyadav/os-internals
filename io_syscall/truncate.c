#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char *argv[]){

	int trunc;
	trunc=truncate("omega.txt",10);
	if(trunc==-1)
		perror("Error:");
	return 0;
}
