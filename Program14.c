#include<stdio.h>
#define MAX 100
int stack[MAX],top=-1;
int auxStack[MAX],auxTop=-1;
int isEmpty(int top)
{
    if(top==-1)
        return 1;
    else
        return 0; 
}
void push(int data)
{
    if(top==MAX-1)
        printf("\nStack Overflow");
    else
    {
        stack[++top]=data;
        if(isEmpty(auxTop))
        {
            auxStack[++auxTop]=data;
        }  
        else{
            if(data<=auxStack[auxTop])
            {
                auxStack[++auxTop]=data;
            }
        }
    }    
}
void pop()
{
    int del;
    if(top==-1)
    {
        printf("\nStack empty.");
    }
    else{
        del=stack[top--];
        if(del==auxStack[auxTop])
        {
            auxTop--;
        }
        printf("\nDeleted : %d",del);
    }
}
void displayStack()
{
    if (top==-1)
        printf("\nStack empty");
    else
    {
        printf("\n");
        for (int i=0;i<=top;i++)
        {
            printf("%d\n", stack[i]);
        }
    }
}
void displayMin()
{
    if(auxTop==-1)
        printf("\nStack Empty");
    else
        printf("\nMinimum Element : %d",auxStack[auxTop]);    
}
int main()
{
    int ch,element;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display stack");
        printf("\n4.Display min");
        printf("\n5.Exit\n");
        printf("\nEnter an operation\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter element to insert\n");
            scanf("%d",&element);
            push(element);
            break;

            case 2:
                pop();
                break;

            case 3:
                displayStack();
                break;

            case 4:
                displayMin();
                break;            
        }
    }while(ch<5);
    return 0;
}