#include <stdio.h>
#include <stdlib.h>


struct Node{
	int data;
	struct Node *left;
	struct Node *right;

};

struct Node *insert_node(int data)
{
	struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));

	new_node->data=data;

	new_node->left=NULL;
	new_node->right=NULL;

	return new_node;
}

void display_inorder(struct Node *root)
{
	if(root!=NULL){
		display_inorder(root->left);
		printf("%d ",root->data);
		display_inorder(root->right);
	}
	
}
int main(){

	struct Node *new_node;
	new_node=insert_node(5);

	new_node->left=insert_node(10);
	new_node->right=insert_node(15);
	new_node->left->left=insert_node(20);
	new_node->left->right=insert_node(25);
	new_node->right->right=insert_node(50);
	new_node->right->left=insert_node(30);

	
	display_inorder(new_node);
	return 0;

}
