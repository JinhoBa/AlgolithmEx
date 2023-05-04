#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAX_QUEUE_SIZE 100
char stack[MAX_STACK_SIZE];

void push(char data);
char pop();

int top = -1;
int main()
{
    char word[100], schar, ochar;
    int slen,i, p = 1;

    printf("Enter word...");
    scanf("%s", word);
    slen = strlen(word);

    for (i = 0; i < slen; i++)
        push(word[i]);

    for (i = 0; i < slen; i++) {
        schar = pop();
        ochar = word[i];
        if (schar != ochar) {
            printf("False\n");
            p = 0;
            break;
        }
    }
    if (p == 1)
        printf("True\n");
}

void push(char item)
{
    if (top >= MAX_STACK_SIZE - 1)
        printf("Stack is overflow !!!\n");
    else {
        top++;
        stack[top] = item;
    }
}

char pop()
{
    if (top == -1) {
        printf("Stack is empty!!!");
    }
    else return stack[top--];
}