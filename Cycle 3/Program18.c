#include<stdio.h>
#define MAX 100
char stack[MAX],top=-1;
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
        printf("\nStack empty.");
        return '\0';
    }
    else
    {
        del=stack[top--];
        return del;
    }
}
void display()
{
    if(top==-1)
        printf("\nStack empty");
    else
    {
        printf("\n");
        for(int i=0;i<=top;i++)
        {
            printf("%c\n",stack[i]);
        }
    }    
}
int isMatchingPair(char character1,char character2)
{
    if(character1=='('&&character2==')')
        return 1;
    else if(character1=='{'&&character2=='}')
        return 1;
    else if(character1=='['&&character2==']')
        return 1;
    else    
        return 0;            
}
int isOpeningBracket(char ch)
{
    if(ch=='('||ch=='{'||ch=='[')
        return 1;
    else    
        return 0;    
}
int isClosingBracket(char ch)
{
    if(ch==')'||ch=='}'||ch==']')
        return 1;
    else
        return 0;    
}
int areBracketsBalanced(char exp[])
{
    int i=0;
    while(exp[i]!='\0')
    {
        if(isOpeningBracket(exp[i]))
            push(exp[i]);
        else if(isClosingBracket(exp[i]))
        {
            if(top==-1)
                return 0;
            else
            {
                if(isMatchingPair(pop(),exp[i]))
                {

                }
                else
                {
                    return 0;
                }
            }
        }
        i++;
    }
    if(top==-1)
        return 1;
    else    
        return 0;    
}
int main()
{
    char exp[MAX];
    printf("Enter an experession : ");
    scanf("%s",exp);
    int flag=areBracketsBalanced(exp);
    if(flag)
        printf("Balanced\n");
    else   
        printf("Not Balanced\n");    
    return 0;    
}