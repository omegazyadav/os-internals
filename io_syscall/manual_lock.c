#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pirate{
	char name[100];
	unsigned int beard_len;
}p1,p2={"omega",10};


int main(int argc, char *argv[]){

	FILE *fp;
	char *buf;
	
	fp=fopen("file.txt","w");
	if(!fwrite(&p2,sizeof(p1),1,fp))
		perror("write:");


	// Getting the file descriptor of the associated stream. 
	int fd;
	fd=fileno(fp);
	if(fd==-1)
		perror("fd:");

	printf("The associated syscall of the stream is :%d\n",fd);

	// Locking the thread for multiple write operation. 

	flockfile(fp);
	fputs("List of treasure:\n",fp);
	fputs("   (1) 500 gold coins\n",fp);
	fputs("   (2) Wonderfully ornate dishware\n",fp);
	funlockfile(fp);

	fclose(fp);
	return 0;

}
