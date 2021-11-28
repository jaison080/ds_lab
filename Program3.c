#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,n,count;
	char a[100];
	printf("Enter the string in lower case\n");
	scanf("%[^\n]",a);
	printf("Frequency of letters in a string\n");
	n=strlen(a);
	for(i=0;i<n;i++)
	{
		count=1;
		if(a[i])
    		{
 			for(j=i+1;j<n;j++)  
	     	 	{   
	    			if(a[i]==a[j])
    	    			{
                 			count++;
                 			a[j]='\0';
	     			}
	      		}  
	      		printf("'%c' = %d \n",a[i],count);
	 	}
	} 
	return 0;
}	
