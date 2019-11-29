#include <stdio.h>
#include <stdlib.h>


struct Node {
	int data;
	struct Node *next;
};

struct Node *top=NULL;
struct Node *push(struct Node *,int);
struct Node *display(struct Node *);
struct Node *pop(struct Node *);

int main(void){

	int val,num;
	printf("\nSelect the number:\n 1. Push into the stack\n 2. Display the elements\n 3. Pop the element:\n 4. Exit the menu\n");

	do{

			printf("Enter the number:\n");
			scanf("%d",&num);


		switch(num){
		case 1:
		{
			printf("Enter the value to insert into the stack.\n ");
			scanf("%d",&val);
			top=push(top,val );
			break;
		}
		case 2:
		{
			printf("Displaying the elements of the stack:\n");
			top=display(top);
			break;

		}
		case 3:
		{
			top=pop(top);
			break;
		}
		default:
			break;			
	}			
	}while(num!=4);
	

	return 0;
}


struct Node *push(struct Node *top, int val)
{
	struct Node *ptr;	
	ptr=(struct Node *)malloc(sizeof(struct Node));
	ptr->data=val;

	if(top==NULL){
		ptr->next=NULL;
		top=ptr;
	}else{
		ptr->next=top;
		top=ptr;		
	}
	return top;
}

struct Node *pop(struct Node *top)
{
	struct Node *ptr;
	ptr=top;
	if(top==NULL){
		printf("Stack is empty. \n");
	}else {	
		top=top->next;
		printf("The value %d is deleted from the stack. \n",ptr->data);
		free(ptr);
		
	}
	return top;
}

struct Node *display(struct Node *top)
{
	struct Node *ptr;
	ptr=top;
	if (ptr==NULL)
		printf("Stack is empty. \n");
	else{
		while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
		}

	}
	return top;
}
