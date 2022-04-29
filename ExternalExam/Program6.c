#include<stdio.h>
#define MAX 100
int arr[MAX];
int n,flag,m,x,temp;
int BinarySearch(int arr[],int l,int u,int w)
{
    
    if(u>=l)
    {
        m=l+(u-l)/2;
        if(arr[m]==w)
        {
            return m;
        }
        if(arr[m]>w)
        {
            return BinarySearch(arr,l,m-1,w);
        }
        if(arr[m]<w)
        {
            return BinarySearch(arr,m+1,u,w);
        }
    }
    return -1;
}
void BubbleSort(int arr[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
    printf("Enter the no : of integers : ");
    scanf("%d",&n);
    printf("Enter the values\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    BubbleSort(arr);
    printf("Enter the element to be searched : ");
    scanf("%d",&x);
    int r=BinarySearch(arr,0,n-1,x);
    if(r!=-1)
        printf("Element found\n");
    else
        printf("Element not found\n");
    return 0;
}