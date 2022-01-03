#include<stdio.h>
#include<stdbool.h>
#define MAX 20
int q[MAX];
int front=-1,rear=-1;
bool qIsFull()
{
    return rear==MAX-1;
}
bool qIsEmpty()
{
    return front==-1&&rear==-1;
}
void enqueue(int el)
{
    if(qIsFull())
        printf("\nQueue full");
    else
    {
        if(qIsEmpty())
            front=rear=0;
        else
        {
            rear++;
        }    
        q[rear]=el;
    }    
}
void dequeue()
{
    int deleted;
    if(qIsEmpty())
    {
        printf("Queue Empty");
    }
    else
    {
        deleted=q[front];
        if(front==rear)
            front=rear-1;
        else
            front++;
        printf("\nDeleted from queue : %d",deleted);    
    }
}
void printQ()
{
    if(qIsEmpty())
        printf("\nQueue Empty");
    else
    {
        printf("\nElements of Queue \n");
        for(int i=front;i<=rear;i++)
            printf("%d\n",q[i]);
    }
}
int main()
{
    int ch,element;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display Queue");
        printf("\n4.Exit\n\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter element to insert : ");
                scanf("%d",&element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printQ();
                break;
        }
    }while(ch<4);
    return 0;
}