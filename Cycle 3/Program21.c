#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
int stack[MAX], top = -1;
void push(int data)
{
    if (top == MAX - 1)
    {
        printf("\nStack overflow\n Aborting\n");
        exit(0);
    }
    else
        stack[++top] = data;
}
int pop()
{
    int del;
    if (top == -1)
    {
        printf("\nStack empty\n Invalid Expression\n");
        exit(0);
    }
    else
    {
        del = stack[top--];
        return del;
    }
}
int peek()
{
	if(top == -1)
		return -1;
	else
		return stack[top];
}
void display()
{
    if (top == -1)
        printf("\nStack empty");
    else
    {
        printf("\n");
        for (int i = 0; i <= top; i++)
        {
            printf("%d, ", stack[i]);
        }
    }
}
int isOperand(char ch)
{
    return  (isdigit(ch));
}

int evalPostfix( char exp[] )
{
    for(int i=0; i<strlen(exp); i++)
    {
        if(isOperand(exp[i]))
        {
            push(exp[i]-'0');
        }
        else
        {
            int op2 = pop();
            int op1 = pop();
            int result;
            switch(exp[i])
            {
                case '+':
                    result = op1+op2;
                    break;
                case '-':
                    result = op1-op2;
                    break;
                case '*':
                    result = op1*op2;
                    break;
                case '/':
                    result = op1/op2;
                    break;
                default:
                    printf("Unknown operator\n");
                    exit(0);
            }
            push(result);
        }
    }
    return pop();
}

int main()
{
    char exp[MAX]="23+";
    printf("Enter a valid postfix expression: ");
    scanf("%s",exp);
    int result = evalPostfix(exp);
    printf("Result : %d \n",result);

    return 0;
}