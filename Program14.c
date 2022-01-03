#include<stdio.h>
#define MAX_SIZE 100
int queue[MAX_SIZE],p=-1,k=0;
void enqueue(int data)
{
	if(p==MAX_SIZE-1)
		printf("\nQueue full.");
	else
		queue[++p]=data;	
}
void dequeue()
{
	int d;
	if(p==-1)
		printf("\nQueue empty.");
	else
	{
		
		d=queue[k];
		printf("Deleted : %d\n",d);
		k++;
	}	
}
void display()
{
    if(p==-1)
        printf("Queue empty.\n");
    else
    {
        printf("\n");
        for(int i=k;i<=p;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
}
int main()
{
	int ch,element;
	do
	{
		printf("\nChoose operation\n");
		printf("\n1.Enqueue");
		printf("\n2.Dequeue");
		printf("\n3.Print queue");
		printf("\n4.Exit");
		printf("\n\nEnter an option\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the element to enqueue\n");
				scanf("%d",&element);
				enqueue(element);
				break;
			
			case 2:	
				dequeue();
				break;
			
			case 3:
				display();
				break;	
		}
	}while(ch<4);
	return 0;
}
