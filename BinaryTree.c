#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct  node * getNode(int data){
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Insufficient memory");
        exit(0);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(struct node *root){
    if(root == NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root){
    if(root == NULL){
        return ;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int countNodes(struct node *root){
    int c;
    if(root == NULL){
        return 0;
    }
    c = 1 + countNodes(root->left) + countNodes(root->right);
    return c;
}

int countLeafnodes(struct node *root){
    int c;
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    c = countLeafnodes(root->left) + countLeafnodes(root->right);
    return c;
}

int countNonLeafNodes(struct node *root){
    int c, c1, c2;
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 0;
    c1 = countNonLeafNodes(root->left);
    c2 = countNonLeafNodes(root->right);
    c = 1 + c1 + c2;
    return c;
}

int max(struct node *root){
    int m1, m2, maxval;
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL)
        return root->data;
    
    m1 = max(root->left);
    m2 = max(root->right);
    maxval = (m1>m2)? m1: m2;
    if(root->data>maxval)
        return root->data;
    return maxval;
}


int main(){
    struct node *root = NULL;
    root = getNode(50);
    root->left = getNode(40);
    root->right = getNode(600);
    root->right->right = getNode(10);
    root->left->left = getNode(30);
    root->left->right = getNode(70);
    printf("Inorder : ");
    inorder(root);
    printf("\n");
    printf("Preorder : ");
    preorder(root);
    printf("\n");
    printf("Postorder : ");
    postorder(root);
    printf("\n");

    printf("Number of nodes are : %d\n", countNodes(root));
    printf("Number of Leaf nodes are : %d\n", countLeafnodes(root));
    printf("Number of Non Leaf nodes are : %d\n", countNonLeafNodes(root));
    printf("max : %d\n", max(root));
    return 0;
}