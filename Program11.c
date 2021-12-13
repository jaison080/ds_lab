#include<stdio.h>
struct matrix{
    int row;
    int column;
    int value;
};
int main(){
    struct matrix a[20],b[20];
    int n,m,i,j,k,flag;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    printf("Enter the number of columns: ");
    scanf("%d",&m);
    a[0].row=n;
    a[0].column=m;
    int ctr=0,c=1;
    for(i=0;i<n;i++)
    for(j=0;j<m;j++){
        printf("Enter the element: ");
        scanf("%d",&k);
        if(k!=0){
            a[c].row=i;
            a[c].column=j;
            a[c].value=k;
            ctr++;
            c++;
            
        }
    }
    a[0].value=ctr;
    b[0].row=a[0].column;
    b[0].column=a[0].row;
    b[0].value=a[0].value;
    int z=a[0].value;
    c=1;
    if(z>0){
        for(i=0;i<=a[0].column;i++){
            for(j=1;j<=z;j++){
                if(a[j].column==i){
                    b[c].row=a[j].column;
                    b[c].column=a[j].row;
                    b[c].value=a[j].value;
                    c++;
                }
            }
        }
    }