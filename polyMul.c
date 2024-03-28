#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coff;
    int expo;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *head3 = NULL;

struct node* getNode(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Insufficient Memory\n");
        exit(0);
    }
    newnode->next = NULL;
    return newnode;
}

struct node* insert(struct node* head, int coff, int expo){
    struct node *newnode = getNode();
    struct node *last;
    newnode->coff = coff;
    newnode->expo = expo;
    if(head == NULL || head->expo<expo){//empty list or given expo is greater than existing poly expo
        newnode->next = head;
        head = newnode;
    }else{
        last = head;
        while(last->next != NULL && last->next->expo > expo){//next node expo greater than given expo
            last = last->next;
        }
        if(last->next != NULL && last->next->expo == expo){//updation when expo is exists
            last->next->coff = newnode->coff + last->next->coff;
            return head;
        }
        newnode->next = last->next;
        last->next = newnode;
    }
    return head;
}

struct node* create(struct node *head){
    int n, coff, expo;
    printf("How many term?\n");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter the coifficient!\n");
        scanf("%d", &coff);
        printf("Enter the exponent!\n");
        scanf("%d", &expo);
        head = insert(head, coff, expo);
    }
    // // head = insert(head, 1, 2);
    // head = insert(head, 1, 0);
    return head;
}

struct node* polyMul(struct node* head1, struct node* head2){
    struct node *p1, *p2;
    p1 = head1;
    p2 = head2;
    while(p1 != NULL){
        p2 = head2;
        while (p2 != NULL)
        {
            int coff = p1->coff * p2->coff;
            int expo = p1->expo + p2->expo;
            head3 = insert(head3, coff, expo);
            p2 = p2->next;
        }
        p1 = p1->next;
        
    }
    return head3;
}

int  main(){
    printf("Enter the polynominal 1: \n");
    head1 = create(head1);
    printf("Enter the polynominal 2: \n");
    head2 = create(head2);
    head3 = polyMul(head1, head2);
    struct node *last = head3;
    printf("Result : ");
    while(last != NULL){
        printf("%dx^%d " ,last->coff, last->expo);
        last = last->next;
        if(last != NULL)
            printf(" + ");
        else 
            printf(" = 0");
    }
    return 0;
}
