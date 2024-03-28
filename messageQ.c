#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200

struct queue {
char data[SIZE][200];
int front, rear;
};

void enqueue (struct queue *q,char msg[]){
	if (q->front == (q->rear+1)%SIZE){
		printf("overflow");
	}
	else{
	q->rear = (q->rear+1)%SIZE;
	strcpy(q->data[q->rear],msg);
	if (q->front == -1){
		q->front += 1;
	}
	}
}

void dequeue(struct queue *q,char msg[]){
	if (q->front == -1){
		printf("q is empty");
	}
	else{
	if (q->front == q->rear){
		q->front = -1;
		q->rear = -1;
	}
	else{
	q->front = (q->front+1)%SIZE;
	strcpy(msg,q->data[q->front]);
	}
	}
}

void display (struct queue *q){
	int i;
	if (q->rear == -1){
		printf("q is empty");
	}
	else {
	for (i=q->front;i!=q->rear;i=(i+1)%SIZE){
		printf("%s",q->data[i]);
	}
	 printf("%s \n", q->data[i]);
	}
}
int main(){
    struct queue q;
    q.front = -1;
    q.rear = -1;
    int ch, item;
    char msg[200];

    for(;;){
        printf("Insert - 1\n");
        printf("Delete - 2\n");
        printf("Display - 3\n");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("Enter the message\n");
                scanf("%s", msg);
                enqueue(&q, msg);
                break;
            case 2:
                dequeue(&q, msg);
                break;
            case 3:
                display(&q);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
