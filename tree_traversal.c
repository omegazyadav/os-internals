#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *left;
    int data;
    struct node *right;
};

struct node *new_node(int data){

    struct node* node=(struct node*) malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;

}

void preOrderTraversal(struct node * node){
    if (node==NULL)
        return ;
    printf("%d ",node->data);
    preOrderTraversal(node->left);
    

    preOrderTraversal(node->right);

}
void postOrderTraversal(struct node * node){
    if (node==NULL)
        return ;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    printf("%d ",node->data);
}

void inOrderTraversal(struct node *node){
    if(node==NULL)
        return ;

    inOrderTraversal(node->left);
    printf("%d ",node->data);
    inOrderTraversal(node->right);
}


void main()
{
    struct node *root=new_node(1);
    root->left=new_node(2);
    root->right=new_node(3);
    root->left->left=new_node(4);
    root->left->right=new_node(5);


    printf("\nPrint the preorder traversal of the tree:");
    preOrderTraversal(root);
    printf("\nPrint the inorder traversal of the tree:");
    inOrderTraversal(root);
    printf("\nPrint the post order traversal of the tree:");
    postOrderTraversal(root);

    
}
