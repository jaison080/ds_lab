#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct odd
{
    int value;
    struct odd* next;
};
struct even
{
    int val;
    struct even* next;
};
struct odd* first2=NULL;
struct odd* temp2;
struct even* first1=NULL;
struct even* temp1;
struct node* temp;
struct node* first = NULL;
struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc((sizeof(struct node)));
    if(newNode == NULL)
    {
        printf("Sorry there was an error\n Aborting\n");
        exit(0);
    }
    newNode->next = NULL;
    newNode->data = data;
    return(newNode);
}
struct even* createNode1(int data1)
{
    struct even* newNode1 = (struct even*)malloc((sizeof(struct even)));
    if(newNode1 == NULL)
    {
        printf("Sorry there was an error\n Aborting\n");
        exit(0);
    }
    newNode1->next = NULL;
    newNode1->val = data1;
    return(newNode1);
}
struct odd* createNode2(int data2)
{
    struct odd* newNode2 = (struct odd*)malloc((sizeof(struct odd)));
    if(newNode2 == NULL)
    {
        printf("Sorry there was an error\n Aborting\n");
        exit(0);
    }
    newNode2->next = NULL;
    newNode2->value = data2;
    return(newNode2);
}
void insert(int data)
{
    struct node *newNode = createNode(data);

    if(first == NULL)
    {
        first = newNode;
    }
    else
    {
        struct node *temp = first;
        while(temp->next !=NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void print()
{
    temp=first;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void Even()
{
    temp=first;
    while(temp->next!=NULL)
    {
        if((temp->data)%2==0)
        {
            struct even *newNode1 = createNode1(temp->data);

            if(first1 == NULL)
            {
                first1 = newNode1;
            }
            else
            {
                temp1= first1;
                while(temp1->next !=NULL)
                {
                    temp1 = temp1->next;
                }
                temp1->next = newNode1;
            }
        }
        temp=temp->next;
    }
}
void Odd()
{
    temp=first;
    while(temp->next!=NULL)
    {
        if((temp->data)%2!=0)
        {
            struct odd *newNode2 = createNode2(temp->data);

            if(first2 == NULL)
            {
                first2 = newNode2;
            }
            else
            {
                temp2= first2;
                while(temp2->next !=NULL)
                {
                    temp2 = temp2->next;
                }
                temp2->next = newNode2;
            }
        }
        temp=temp->next;
    }
}
void printEven()
{
    temp1=first1;
    while(temp1!=NULL)
    {
        printf("%d  ",temp1->val);
        temp1=temp1->next;
    }
    printf("\n");
}
void printOdd()
{
    temp2=first2;
    while(temp2!=NULL)
    {
        printf("%d  ",temp2->value);
        temp2=temp2->next;
    }
    printf("\n");
}
int main()
{
    int choice,r;
    do
    {
        printf("1.Insert\n");
        printf("2.Print all\n");
        printf("3.Print even\n");
        printf("4.Print odd\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the value : ");
                scanf("%d",&r);
                insert(r);
                break;
            }
            case 2:
            {
                print();
                break;
            }
            case 3:
            {
                Even();
                printEven();
                break;
            }
            case 4:
            {
                Odd();
                printOdd();
                break;
            }
        }
    }while(choice<=4);
}