#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 20

struct stack{
int top;
int a[SIZE];
};

typedef struct stack STACK;

void push (STACK *s,int ele){
if (s->top == SIZE-1){
printf("overflow");
return;
}
s->top = s->top+1;
s->a[s->top] = ele;
}

int pop(STACK *s){
if (s->top == -1){
printf("underflow");
return 0;
}
int x = s->a[s->top];
s->top = s->top-1;
return x;
}

float compute(float op1,float op2,char symbol){

	switch(symbol){
	case '+': 
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}
}

float postfixeval(char postfix[],STACK *s){
	float op1,op2,result;
	char symbol;
	for (int i=0;postfix[i]!='\0';i++){
	     symbol =postfix[i];
	     if (symbol >= '0' && symbol <= '9'){
	     push(s,symbol -'0');
	     }
	     else{
	     op1 = pop(s);
	     op2 = pop(s);
	     result = compute(op1,symbol,op2);
	     push(s, result);
	     }
	}
	return pop(s);
}

int main(){
STACK s;
s.top = -1;
char postfix[20];
float result;
printf("input the postfix expression:");
scanf("%s",postfix);
result = postfixeval(postfix,&s);
printf("final result is %f\n",result);
return 0;
}


 


