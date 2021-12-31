#include<stdio.h>
#define MAX_SIZE 100
int stack[MAX_SIZE],top1=-1,top2=MAX_SIZE-1;
void push(int stackNo,int data)
{
     if (stackNo==1)
    {
        if (top1==top2 - 1)
        {
            printf("\nStack 1 full");
        }
        else
        {
            stack[++top1]=data;
        }
    }
    else if(stackNo==2)
    {
        if (top2==top1+1)
        {
            printf("\nStack 2 full");
        }
        else
        {
            stack[--top2]=data;
        }
    }
}
int pop(int stackNo)
{
    if (stackNo==1)
    {
        if (top1==-1)
        {
            printf("\nStack 1 empty");
            return -1;
        }
        return stack[top1--];
    }
    else if(stackNo==2)
    {
        if (top2==MAX_SIZE)
        {
            printf("\nStack 2 empty");
            return -1;
        }
        return stack[top2++];
    }
}
void display(int stackNo)
{
    if (stackNo==1)
    {
        if (top1==-1)
        {
            printf("\nStack 1 empty");
            return;
        }
        printf("\nElements of stack 1\n");
        for(int i=0;i<=top1;i++)
            printf("%d ",stack[i]);
    }
    else if(stackNo==2)
    {
        if (top2==MAX_SIZE)
        {
            printf("\nStack 2 empty");
            return;
        }
        printf("\nElements of stack 2\n");
        for(int i=MAX_SIZE-1;i>=top2;i--)
            printf("%d ", stack[i]);
    }
}
int main()
{
    int stackNo, ch, element, popped;
    printf("\nEnter stack number (1 or 2) ");
    scanf("%d", &stackNo);
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.Change stack number");
        printf("\nPress anyother key to EXIT\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert ");
            scanf("%d",&element);
            push(stackNo,element);
            break;
        case 2:
            popped=pop(stackNo);
            printf("\nPopped element %d ",popped);
            break;
        case 3:
            display(stackNo);
            break;
        case 4:
            printf("\nEnter stack number (1 or 2)");
            scanf("%d", &stackNo);
            break;
        }
    } while(ch<5);
    return 0;
}