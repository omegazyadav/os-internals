#include <stdio.h>
#include <stdlib.h>

struct rec{
	int a;
	float b;
	char c;

};


int main(int argc,char *argv[]){
	struct rec *r1;
	r1=malloc(sizeof(r1));

	 r1->a=10;
	 r1->b=10.10;
	 r1->c='o';

	printf("Recorded values are: %d, %f, %c\n",r1->a,r1->b,r1->c);
	free(r1);
	return 0;
	
	
}
