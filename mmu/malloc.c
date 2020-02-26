#include <stdio.h>
#include <stdlib.h>

void *xmalloc(size_t size){

	int *p;
	p=malloc(size);
	if(!p)
		perror("Malloc!");
	return p;
}

int main(int argc, char *argv[]){
	int *a;
	a=xmalloc(sizeof(int));
	*a=20;
	printf("The value of a is :%d\n",*a);
	return 0;
	
}
