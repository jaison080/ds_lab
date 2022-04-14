#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
char stack[MAX],top=-1;
int isOperand(char ch)
{
    return(isdigit(ch))||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z');
}
int Prec(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;

    }
    return -1;
}
void push(char data)
{
    if(top==MAX-1)
        printf("\nStack Overflow");
    else
        stack[++top]=data;    
}
char pop()
{
    char del;
    if(top==-1)
    {
        printf("\nStack empty");
        return '\0';
    }
    else
    {
        del=stack[top--];
        return del;
    }
}
char peek()
{
    if(top==-1)
    {
        printf("\nStack empty");
        return '\0';
    }
    else
    {
        return stack[top];
    } 
}
int isEmpty()
{
    return(top==-1);
}
char myStr[2];
char* getStr(char ch)
{
    myStr[0]=ch;
    myStr[1]='\0';
    return myStr;
}
void display()
{
    if(top==-1)
        printf("\nStack empty");
    else
    {
        printf("\n");
        for(int i=0;i<=top;i++)
            printf("%c\n",stack[i]);
    }    
}
void infixToPostfix(char exp[],char output[])
{
    int i,k,n=strlen(exp);
    for(i=0;i<n;i++)
    {
        if(isOperand(exp[i]))
            strcat(output,getStr(exp[i]));
        else if(exp[i]=='(')
        {
            push(exp[i]);
        }
        else if(exp[i]==')')
        {
            while(peek()!='(')
            {
                if(isEmpty())
                {
                    printf("Invalid Expression.\n");
                    exit(0);
                }
                strcat(output,getStr(pop()));
            }
            pop();
        }
        else
        {
            while(!isEmpty()&&(Prec(peek())>=Prec(exp[i])))
            {
                strcat(output,getStr(pop()));
            }
            push(exp[i]);
        }
    }
    while(!isEmpty())
    {
        if(peek()=='('||peek()==')')
        {
            printf("Invalid.\n");
            exit(0);
        }
        strcat(output,getStr(pop()));
    }
}
int main()
{
    char exp[MAX]="(2+3)*4";
    printf("Enter a valid Infix Expression : ");
    scanf("%s",exp);
    char output[MAX];
    output[0]='\0';
    infixToPostfix(exp,output);
    printf("\nPostfix : %s\n",output);
    return 0;
}