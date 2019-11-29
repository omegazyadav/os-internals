#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};
int val;
struct Node *head=NULL;
struct Node *insert_end(struct Node *,int );
struct Node *display(struct Node *);

int main(void)
{

	int option;
	printf("1. For Insertion:\n 2. For Displaying.\n");

	do{
	printf("\nEnter the option:");
	scanf("%d",&option);
	switch(option)
	{
		case 1:
		{
			printf("\nEnter the value:");
			scanf("%d",&val);
			
			head=insert_end(head,val);
			break;

		}
		case 2:
		{
			printf("Displaying the elements of the linked list:\n");
			head=display(head);
			break;
		}
		
	}

	}while(option!=3);

	return 0;
}


struct Node *insert_end(struct Node *head,int val)
{
	struct Node *new_node,*ptr;
	new_node=(struct Node *)malloc(sizeof(struct Node));
	new_node->data=val;
	new_node->next=NULL;
	ptr=head;	

	if(ptr==NULL){
		head=new_node;
	}else{
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=new_node;

	}
	return head;
}

struct Node *display(struct Node *head)
{
		display(head->next);
		printf("%d",head->data);
//	struct Node *ptr;
//	ptr=head;
//	while(ptr!=NULL){
//		printf("%d ",ptr->data);
//		ptr=ptr->next;
//	}
	return head;
}
