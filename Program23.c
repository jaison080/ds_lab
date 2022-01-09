#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* first=NULL;
struct node* createNode()
{
    struct node* newNode=(struct node*)malloc((sizeof(struct node)));
    if(newNode!=NULL)
        newNode->next=NULL;
    return();
}
void createElem(int data)
{
    struct node* newNode=createNode();
    if(newNode==NULL)
    {
        printf("Sorry there was an error\nAborting\n");
        exit(0);
    }
    else
    {
        if(first==NULL)
            first=newNode;
        newNode->data=data;
    }
}
int main()
{
    do
    {
        int choice,data;
        printf("1.Add elements\n");
        printf("2.Display Elements\n");
        printf("3.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value : ");
                scanf("%d",&data);
                createElem(data);
                break;
        }
    }while(choice<3)
    return 0;
}