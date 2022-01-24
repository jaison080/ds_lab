#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL,*temp,*newnode;
struct node *create(int item){
   struct node *newNode=(struct node*) malloc(sizeof(struct node ));
    newNode->data=item;
    newNode->next=NULL;
    return newNode;
}
void add(int item){
    newnode=create(item);
    
    if(head==NULL){
        head=newnode;
        
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;

    }
}
void display(){
    
    if(head==NULL){
        printf("Empty");
    }
    else{
        temp=head;
        while(temp!=NULL){
            printf("Data: %d\n",temp->data);
            temp=temp->next;
        }
    }
}
void delete(int item){
    struct node *del;
    if(item==head->data){
        temp=head->next;
        del=head;
        head=temp;
        free(del);
    }
    else{
        struct node *del = NULL;
        temp=head;

        if(head->data ==item)
        {
            del = head;
            head = head->next;
            free(del);
            printf("\nElement Deleted! \n");
        }
        else
        {
            while(temp != NULL)
            {
                if(temp->next!=NULL && temp->next->data == item)
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
int small(){
    temp=head;
    int smaller=temp->data;
    while(temp!=NULL){
        if(temp->data<smaller){
            smaller=temp->data;
        }
    }
    return smaller;
}
void deletesmall(){
    int smaller=small();
    delete(smaller);
    printf("Smallest element deleted...");

}
int main(){
    int ch;
    int state=0;
    while(state==0){
        printf("1. add 2. delete small 3 display 4 exit");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("enter the data to be added: ");
                int item;
                scanf("%d",&item);
                add(item);
                break;
            }
            case 2:{
                deletesmall();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                state=1;
                break;
            }
        }
    }
}
