#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_SIZE 100

int main(int argc, char *argv[]){

	char buf[FILE_SIZE];
	char *ptr="I am a Kernel Engineer. ";
	int c;

	FILE *fp;
	fp=fopen("file.txt","a+");

// Reading one charactr at a time. 

//	while((c=fgetc(fp))!=EOF){
//		printf("%c",(char) c);
//	}

// Writing a stream into the file. 
//	fputs(ptr,fp);

	if(!fwrite(ptr,strlen(ptr),1,fp))
		perror("write:");
	fclose(fp);


// Reading entire line at once.

	fp=fopen("file.txt","a+");

	ssize_t nr;
	nr=fread(buf, FILE_SIZE, 1, fp);
	if(nr==0)
		perror("fread:");

//	if((fgets(buf, FILE_SIZE, fp))!=NULL)
//			puts(buf);
	printf("%s\n",buf);

	fclose(fp);
	return 0;
	
}


