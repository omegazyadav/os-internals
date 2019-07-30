#include <stdio.h>
#define MAX_FILE_NAME 100

int main(){
	FILE* fp;
	//character counter 
	
	int count=0;

	char filename[MAX_FILE_NAME];
	
	//to store a character read from file
	char c;
	
	printf("Enter the filename:\n");
	scanf("%s",filename);

	//open the file
	
	fp=fopen(filename,"r");

	//check if file exists
	
	if (fp==NULL){
		printf("Counld not open the file%s",filename);
		return 0;
		
	}

	for (c=getc(fp);c!=EOF;c=getc(fp))
		count+=1;

	fclose(fp);

	printf("Total character in a file is :%d",count);
	return 0;
}
