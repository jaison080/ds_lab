#include<stdio.h>
struct matrix{
    int row;
    int column;
    int value;
};
int main()
{
    int n,i,j,m,a[20][20];
    struct matrix k[300];
    printf("Enter the matrix\n");
    printf("Enter the number of rows \n");
    scanf("%d",&n);
    printf("Enter the number of columns\n");
    scanf("%d",&m);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    k[0].row=n;
    k[0].column=m;
    int c=1;
    int p=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]!=0)
            {
                k[c].row=i;
                k[c].column=j;
                k[c].value=a[i][j];
                c++;
                p++;
            }
        }
    }
    int l=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]==0)
            {
                l++;
            }
        }
    }
    k[0].value=p;
    printf("\n\n");
    printf("Row\tColumn\tValue\n");
    for(i=0;i<=p;i++)
    {
        printf("%d\t%d\t%d\n",k[i].row,k[i].column,k[i].value);
    }
    float num,sparsity;
    num=m*n;
    sparsity=l/num;
    printf("Sparsity of a matrix : %f",sparsity);
}