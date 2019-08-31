#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(int argc,char * argv[]){
#define STR "Hello, world\n"
	write(STDOUT_FILENO,STR,strlen(STR));
	exit(EXIT_SUCCESS);
}
