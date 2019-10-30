/* POSIX implementation 
 *
 * function definition : void out(void);
 */

#include <stdio.h>
#include <stdlib.h>


void out(void){

	printf("atexit() succeded!\n");
}
int main(void){
	if(atexit(out))
		fprintf(stderr,"atexit() failed!\n");

	return 0;
}
