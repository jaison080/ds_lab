#include <stdio.h>
#define MAX 100
int arr1[MAX],arr2[MAX];
int front1=0,front2=0,rear1=0,rear2=0,flag=0;
void insert1(int x)
{
    if(front1==-1)
    {
        front1=0;
        arr1[rear1++]=x;
    }
    else
        arr1[rear1++]=x;
}
void insert2(int x)
{
    if(front2==-1)
    {
        front2=0;
        arr2[rear2++]=x;
    }
    else
        arr2[rear2++]=x;
}
void delete1()
{
    printf("Deleted : %d\n",arr1[front1]);
    ++front1;
}
void delete2()
{
    printf("Deleted : %d\n",arr2[front2]);
    ++front2;
}
void print1()
{
    for(int i=front1;i<rear1;i++)
        printf("%d  ",arr1[i]);
    printf("\n");
}
void print2()
{
    for(int i=front2;i<rear2;i++)
        printf("%d  ",arr2[i]);
    printf("\n");
}
void isEqual()
{
    for(int i=front1,j=front2;i<rear1,j<rear2;i++,j++)
    {
            if(arr1[i]==arr2[j])
                flag=1;
            else
            {
                flag=0;
                break;
            }
    }
    if(flag==1)
        printf("Queues are equal.\n");
    else
        printf("Queues are not equal.\n");
}
int main()
{
    int choice,n;
    do
    {
        printf("\n1.Enter elements for Queue 1\n");
        printf("2.Enter elements for Queue 2\n");
        printf("3.Delete elements for Queue 1\n");
        printf("4.Delete elements for Queue 2\n");
        printf("5.Display elements for Queue 1\n");
        printf("6.Display elements for Queue 2\n");
        printf("7.Check whether queues equal or not\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the value : ");
                scanf("%d",&n);
                insert1(n);
                break;
            }
            case 2:
            {
                printf("Enter the value : ");
                scanf("%d",&n);
                insert2(n);
                break;
            }
            case 3:
            {
                delete1();
                break;
            }
            case 4:
            {
                delete2();
                break;
            }
            case 5:
            {
                print1();
                break;
            }
            case 6:
            {
                print2();
                break;
            }
            case 7:
            {
                isEqual();
                break;
            }
        }
    }while(choice<=7);
}