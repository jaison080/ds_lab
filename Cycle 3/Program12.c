#include<stdio.h>
#define MAX_SIZE 100
int stack[MAX_SIZE],top=-1;
void push(int data)
{
    if(top==MAX_SIZE-1)
        printf("Stack Overflow\n");
    else
    stack[++top]=data;
}
void pop()
{
    int d;
    if(top==-1)
        printf("Stack Empty\n");
    else
    {
        d=stack[top--];
        printf("Deleted : %d\n",d);
    }    
}
void display()
{
    if(top==-1)
        printf("Stack empty.\n");
    else
    {
        printf("\n");
        for(int i=0;i<=top;i++)
        {
            printf("%d\n",stack[i]);
        }
    }
}
int main()
{
    int ch,element;
    do
    {
        printf("\nChoose operation");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display Stack");
        printf("\n4.Exit");
        printf("\nEnter an option\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the element to insert\n");
                scanf("%d",&element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;        
        }
    }while(ch<4);
    return 0;
}