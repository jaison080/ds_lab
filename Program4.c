#include<stdio.h>
int main()
{
	int a[100],b[100],c[100],i,j,k=0,n1,n2;
	printf("Enter the no of elements in set A\n");
	scanf("%d",&n1);
	printf("Enter the elements of set A\n");
	for(i=0;i<n1;i++)
		scanf("%d",&a[i]);
	printf("Enter the no of elements in set B\n");
	scanf("%d",&n2);	
	printf("Enter the elements of set B\n");
	for(i=0;i<n2;i++)
		scanf("%d",&b[i]);
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(a[i]==b[j])
			{
				c[k]=a[i];
				k++;
			}
		}
	}
	printf("Intersection of set A and set B\n");
	for(i=0;i<k;i++)
		printf("%d,",c[i]);
	printf("\n");	
	return 0;
}						
