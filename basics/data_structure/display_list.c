#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *insert_end(struct Node *head,int num)
{
	struct Node *new_node;

	new_node=(struct Node *)malloc(sizeof(struct Node));
	new_node->data=num;
	new_node->next=NULL;

	struct Node *temp;
	temp=head;


	if (temp==NULL){
		head=new_node;	
	}else{
		while(temp->next!=NULL){
			temp=temp->next;	
		}

		temp->next=new_node;
	}
	return head;	
}

struct Node *display(struct Node *head)
{
	struct Node *temp;
	temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
		
	}

	return head;

}


int main(void)
{
	struct Node *new_node,*head;
	for(int i=0;i<10;i++){
		head=insert_end(head,i);
	}
	head=display(head);

	return 0;
}
