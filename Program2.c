#include<stdio.h>
int main()
{
	int i,j,a[100],b[100],n,sum,temp,c=0,max=0,mode,k;
	float mean,median;
	printf("Enter the number of elements in the array\n");
	scanf("%d",&n);
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		sum=sum+(float)a[i];\
	mean=(float)sum/(float)n;
	printf("Mean of given data : %f\n",mean);	
 	for(i=0;i<n;i++)
  	{
  		for(j=i+1;j<n;j++)
   		{
   			if(a[i]>a[j])
    			{
    				temp=a[i];
    				a[i]=a[j];
    				a[j]=temp;
    			}
   		}
  	}
  	if(n%2==0)
  		median=(float)(a[n/2]+a[(n-1)/2])/2;
  	else
  		median=a[(n-1)/2];	
  	printf("Median of the given data : %f\n",median);
  	for(i=0;i<n-1;i++)
  	{
  		mode=0;
  		for(j=i+1;j<n;j++)
   		{
   			if(a[i]==a[j])
   				mode++;
    		}
  		if((mode>max)&&(mode!=0))
   		{
   			k=0;
   			max=mode;
   			b[k]=a[i];
   			k++;
   		}
  		else if(mode==max)
   		{	
   			b[k]=a[i];
   			k++;
   		}
  	}
 	for(i=0;i<n;i++)
  	{
  		if(a[i]==b[i])
  		c++;
  	}
 	if(c==n)
 		printf("There is no mode");
 	else
  	{
  		printf("Mode of the given data = ");
  		for(i=0;i<k;i++)
  		printf("%d ",b[i]);
  	}
  	return 0;
 }		
