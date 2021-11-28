#include<stdio.h>
int main()
{
	int n,i,j,a[20][20],c[20],k=1,r;
	long int h;
	printf("Enter the no of rows\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
		for(j=0;j<4;j++)
    			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
	{
		c[i]=(a[i][0]*1000)+(a[i][1]*100)+(a[i][2]*10)+a[i][3];
	}
	printf("Hexadecimal values\n");
	for(i=0;i<n;i++)
	{
		h=0;
		while (c[i]!=0)
		{
      			r=c[i]%10;
      			h=h+r*k;
      			k=k*2;
      			c[i]=c[i]/10;
   		}
   		printf("%lX\n",h);
   	}
   	return 0;
} 
