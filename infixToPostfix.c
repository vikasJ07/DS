#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 5

struct stack {
    int top;
    int data[SIZE];
};

typedef struct stack STACK;

void push(STACK *s, int item){
    if (s->top==SIZE-1){
        printf("STack overflow\n");
        return;
    }

    s->top = s->top+1;
    s->data[s->top] = item;
}

int pop(STACK *s){
    if (s->top==-1)
    {
        printf("Stack underflow\n");
        return 0;
    }
    int x = s->data[s->top];
    s->top = s->top-1;
    return x;
}

void display(STACK *s){
    if (s->top==-1)
    {
        printf("Stack underflow\n");
        return;
    }
    printf("Stack elements are\n");
    for (int i=s->top; i>=0; i--)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int isAlphanumeric(char ch) {
    return isalnum((unsigned char)ch);
}

int precedence(char ch) {
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[20], STACK *s){
    
    char postfix[20], symbol, temp;
    int i=0, j=0;
    for (int i = 0; infix[i] != '\0' ; i++)
    {
        symbol = infix[i];
        if(isAlphanumeric(symbol)){
            postfix[j] = symbol;
            j++;
        }else{
            switch (symbol)
            {
            case '(':
                push(s, symbol);
                break;
            case ')':
                temp = pop(s);
                while(temp != '('){
                    postfix[j] = temp;
                    j++;
                    temp = pop(s);
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                if (s->top==-1 || s->data[s->top]=='(')
                {
                    push(s, symbol);
                }else{
                    while(precedence(s->data[s->top]) >= precedence(symbol) && s->top!=-1 && s->data[s->top]!='('){
                        postfix[j] = pop(s);
                        j++;
                    }
                    push(s, symbol);
                }
                break;
            }
        }
    }
    while(s->top != -1){
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
    printf("Postfix expression is %s\n", postfix);
}

int main(){
    char infix[20];
    STACK s;
    s.top = -1;
    printf("Enter infix exp\n");
    scanf("%s", infix);
    infixToPostfix(infix, &s);
    return 0;
}

