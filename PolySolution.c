#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int a[100];
    int b[100];
    int i,n,x;
    int sum=0;
    printf("Enter the no of terms in polynomial : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Coefficent %d: ",i+1);
        scanf("%d",&a[i]);
        printf("Exponent %d: ",i+1);
        scanf("%d",&b[i]);
    }
    printf("Polynomial : ");
    for(i=0;i<n-1;i++)
        printf("%dx^%d+",a[i],b[i]);
    printf("%dx^%d\n",a[n-1],b[n-1]);
    printf("Enter the value for x : ");
    scanf("%d",&x);
    for(i=0;i<n;i++)
        sum=sum+a[i]*pow(x,b[i]);
    printf("Solution of polynomial : %d",sum);    
}