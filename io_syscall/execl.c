/*
 * Process Management
 */

#include <unistd.h>
#include <stdio.h>

int main(void){

	int ret;
	ret=execl("/home/vim","vi",NULL);
	printf("The value of ret is :%d\n",ret);
	if (ret==-1){
		perror("execl error. ");
	}
	return 0;
}
