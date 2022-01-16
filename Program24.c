
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

void addElemAfter(int data, int nodeBeforeData)
{
    struct node *newNode = createNode(data);

    if(first == NULL)
    {
        printf("List Empty");
    }
    else
    {
        struct node *temp = first;
        while(temp!=NULL && temp->data != nodeBeforeData)
        {
            temp = temp->next;
        }
        if(temp == NULL)
            printf("%d Not found in list",nodeBeforeData);
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Element Inserted");
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
        int data, nodeBeforeData;
        printf("\n");
        printf("1: Add element at end\n");
        printf("2: Add element after a node\n");
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
                printf("[Element will be inserted after first occurence]\n");
                printf("Enter value after which you want to insert new data: ");
                scanf("%d",&nodeBeforeData);
                printf("Enter value to insert after %d: ",nodeBeforeData);
                scanf("%d",&data);
                addElemAfter(data,nodeBeforeData);
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