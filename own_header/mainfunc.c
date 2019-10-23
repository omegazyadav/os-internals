/*This is the main function where user defined header file 
 * header.h is called. The quotaiton "" symbol is used for 
 * user defined header file which denotes that required 
 * header file can be found on the current directory*/


#include<stdio.h>
#include "header.h"

void main(){
	int num1=10;
	int num2=10;
       	int num3;
	
	char  ch;
	printf("Enter the operator:\n");
	scanf("%c",&ch);

	switch(ch){
		case '+':
		{
			num3=add(num1,num2);
			printf("Addition of two numbers is :%d\n",num3);
			break;


		}
		case '-':
		{
			num3=sub(num1,num2);
			printf("Substraction of two numbers is :%d\n",num3);
			break;

		}
		case '*':
		{
			num3=mult(num1,num2);
			printf("Multiplication of two numbers is :%d\n",num3);
			break;
		}
		case '/':
		{
			num3=div(num1,num2);
			printf("Division of two numbers is :%d\n",num3);
			break;

		}
			
		default:
			printf("The final print statement. \n");

	}
}
