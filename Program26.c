#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
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

void addElemEnd(int data)
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

void addElemAtPos(int data, int pos)
{
    if(pos<1)
    {
        printf("INVALID, Index should start from 1\n");
    }
    else if(pos == 1)
    {
        struct node *newNode = createNode(data);
        newNode->next = first;
        first = newNode;
        printf("Element Inserted. \n");
    }
    else if(first == NULL)
    {
        printf("Sorry, List Empty, cannot insert at position %d",pos);
    }
    else
    {
        // There must be atleast pos-1 elements in the list
        int elemNum = 1;
        struct node *temp = first;

        // on exiting temp should point to pos-1
        while(temp!=NULL && elemNum<pos-1)
        {
            temp = temp->next;
            elemNum++;
        }
        if(temp == NULL)
            printf("Sorry, There are only %d nodes in the list", elemNum-1);
        else
        {
            struct node *newNode = createNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Element Inserted. \n");
        }
    }
   
    
}

void display()
{
    if(first == NULL)
        printf("\nList Empty");
    else
    {
        struct node *temp = first;
        printf("Head");
        while(temp != NULL)
        {
            printf(" -> %d", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

void delete(int data)
{
    if(first == NULL)
    {
        printf("\nList Empty");
    }
    else
    {
        struct node *temp = first, *del = NULL;
        if(first->data == data)
        {
            del = first;
            first = first->next;
            free(del);
            printf("\nElement Deleted! \n");
        }
        else
        {
            while(temp != NULL)
            {
                if(temp->next!=NULL && temp->next->data == data)
                {
                    del = temp->next;
                    temp->next = temp->next->next;
                    free(del); 
                    printf("\nElement Deleted! \n");
                    break;
                }
                temp = temp->next;
            }
        }
        if(del == NULL)
            printf("\nElement not found! \n");
    }
}

int main()
{
    int choice;
    do
    {
        int data, pos;
        printf("\n");
        printf("1: Add element at end\n");
        printf("2: Add element at given position\n");
        printf("3: Display Elements\n");
        printf("4: Delete Element\n");
        printf("5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&data);
                addElemEnd(data);
                break;
            case 2:
                printf("Enter position at which you want to insert new data: ");
                scanf("%d",&pos);
                printf("Enter value to insert at position %d: ",pos);
                scanf("%d",&data);
                addElemAtPos(data, pos);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("[First occurence will be deleted]\n");
                printf("Enter value that you want to delete: ");
                scanf("%d",&data);
                delete(data);
                break;
            case 5:
                break;
            default:
                printf("Invalid Choice\n");
                break;
        };
    }while(choice != 5);
    return 0;
}