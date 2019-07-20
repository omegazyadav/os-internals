/*This is the main function where user defined header file 
 * header.h is called. The quotaiton "" symbol is used for 
 * user defined header file which denotes that required 
 * header file can be found on the current directory*/


#include<stdio.h>
#include "header.h"

void main(){
	int num1=10,num2=10, num3;
	num3=add(num1,num2);
	printf("Addition of two numbers is :%d",num3);
}
