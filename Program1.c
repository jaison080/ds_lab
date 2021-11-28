#include<stdio.h>
int rotate(int a[],int n,char d,int cr)
{
    	int last;int first;
	if(d=='r')
	{
		for(int i=0;i<cr;i++)
        	{
        		int last=a[n-1];
    			for (int i=n-2;i>=0;i--)
    			{
        			a[i+1]=a[i];
    			}
    			a[0] = last;
    		}
    	}
    	if(d=='l')
    	{
    		for (int i=0;i<cr;i++)
    		{
        		int first=a[0];
    			for(int i=0;i<n-1;i++)
    			{
        			a[i]=a[i+1];
    			}
    			a[n-1]=first;
   		}
   	}
}
void main()
{
	int a[100],n,cr;
	char d;
	printf("Enter 'l' for rotation to left and 'r' for rotation to right\n");
    	scanf("%c",&d);
   	printf("Enter the no: of elements in the array\n");
    	scanf("%d",&n);
    	printf("Enter the elements of the array\n");
    	for(int i=0;i<n;i++)
    		scanf("%d",&a[i]);
    	printf("Enter the no: of times to be rotated\n");
    	scanf("%d",&cr);	
    	rotate(a,n,d,cr);
    	for (int i=0;i<n;i++)
        	printf("%d,",a[i]);
}				
