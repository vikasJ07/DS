#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct  node *last=NULL;

struct  node * getNode(){
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Insufficient memory");
        exit(0);
    }
    newNode->next = NULL;
    return newNode;
}

void enqueue(int x){
    struct node *newNode = getNode();
    newNode->data = x;
    if(last == NULL){
        last = newNode;
        last->next = newNode;
        return;
    }
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
}

void dequeue(){
    struct node *firstnode;
    if(last == NULL){
        printf("Empty Queue\n");
        return;
    }
    firstnode = last->next;
    if(firstnode == last){
        last = NULL;
    }else{
        last->next = firstnode->next;
    }
    printf("Deleted items is %d\n", firstnode->data);
    free(firstnode);
}

void display(){
    if(last == NULL){
        printf("Empty Queue!\n");
        return;
    }
    struct node *node = last->next;
    printf("Queue elemets are : ");
    while(node->next != last->next){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("%d\n", node->data);
}

int main(){

    int x,ch;
    // Write C code here
   while(1)
   {
       printf(" \n 1. Insert 2. Delete 3. Display 4. Exit \n");
       printf("Enter the choice:");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1: printf("Enter the element to be inserted :");
                   scanf("%d",&x);
                   enqueue(x);
                   break;
           case 2: dequeue();
                   break;
           case 3: display();
                   break;
           default: exit(0);
       }
   }

    return 0;
}