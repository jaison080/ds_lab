#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int top=-1,j=0;
int arr[MAX];
int y;
struct node
{
    int data;
    struct node* next;
};
struct node1
{
    int data1;
    struct node1* next;
};
struct node *first=NULL,*rear=NULL;
struct node* temp;
struct node1 *first1=NULL,*rear1=NULL;
struct node1* temp1;
struct node* createNode(int data)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
struct node1* createNode1(int data)
{
    struct node1* newNode1=(struct node1*)malloc(sizeof(struct node1));
    newNode1->data1=data;
    newNode1->next=NULL;
    return newNode1;
}
void insert(int data)
{
    struct node* newNode=createNode(data);
    if(first==NULL)
    {
        first=newNode;
        rear=newNode;
    }
    else
    {
        while(rear->next!=NULL)
        {
            rear=rear->next;
        }
        rear->next=newNode;
    }
}
void insert1(int data)
{
    struct node1* newNode1=createNode1(data);
    if(first1==NULL)
    {
        first1=newNode1;
        rear1=newNode1;
    }
    else
    {
        while(rear1->next!=NULL)
        {
            rear1=rear1->next;
        }
        rear1->next=newNode1;
    }
}
void printNormal()
{
    temp=first;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}
void printReversed()
{
    temp1=first1;
    while(temp1!=NULL)
    {
        printf("%d  ",temp1->data1);
        temp1=temp1->next;
    }
    printf("\n");
}
void delete()
{
    temp=first;
    printf("Deleted : %d",temp->data);
    first=first->next;
    free(temp);
}
int pop()
{
    return arr[top--];
}
void push(int data)
{
    arr[++top]=data;
}
void toStack()
{
    temp=first;
    while(temp->next!=NULL)
    {
        push(temp->data);
        j++;
        temp=temp->next;
    }
    push(temp->data);
    for(int k=0;k<=j;k++)
    {
        y=pop();
        insert1(y);
    }
}

int main()
{
    int choice,n;
    do
    {
        printf("\n1.Insert to original queue\n");
        printf("2.Delete from original queue\n");
        printf("3.Print original queue\n");
        printf("4.Print reversed queue\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the value : ");
                scanf("%d",&n);
                insert(n);
                break;
            }
            case 2:
            {
                delete();
                break;
            }
            case 3:
            {
                printNormal();
                break;
            }
            case 4:
            {
                toStack();
                printReversed();
                break;
            }
        }
    }while(choice<=3);
   return 0;
}