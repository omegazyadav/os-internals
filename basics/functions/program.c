
/*Calling main function again and again
 *
 * here void main(void) cannot be used since the argument the main function in line no. 
 * integer type. 
 * */


#include<stdio.h>
void main(){
	static int i=5;
	if(--i){
		printf("%d ",i);
		main(10);
	}
}
