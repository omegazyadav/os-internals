/*	This program is a simple directory implementation 	
	in which it outputs the list of the directory and 
	files availabe in the directory.

	#include <dirent.h> 
	 
	 This header file contains the necessary 
	 implementation of the directory and file related data 
	 structures. 

*/


//#include "apue.h"
#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	//Directory pointer 
	DIR *dp;
	
	struct dirent	*dirp;
	
	if (argc != 2)
	printf("usage: ls directory_name");

	if ((dp = opendir(argv[1])) == NULL)
	printf("can’t open %s", argv[1]);

	while ((dirp = readdir(dp)) != NULL)
	printf("%s\n", dirp->d_name);

	closedir(dp);
}
