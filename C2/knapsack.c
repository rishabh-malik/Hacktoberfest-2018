#include<stdio.h>
#include<conio.h>
int main()
{
int i,j,t=0,t1=0,t2=0,t3=0,W=0,k=0;
int C[5],w[5],L[5],I[]={1,2,3,4,5,6};
clrscr();
printf("\nEnter the total capacity\n");
scanf("%d",&k);
printf("\n Enter each item cost \n");
for(i=0;i<5;i++)
{
scanf("%d",&C[i]);
}
printf("\n Enter the item weight\n");
for(i=0;i<5;i++)
{
scanf("%d",&w[i]);
}
printf("\n The input data is");
printf("\n Item No\tCost\tWeight");
printf("\n......\t........\t........\n");
for(i=0;i<5;i++)
{
printf("%d\t\t%d\t\t%d",I[i],C[i],w[i]);
printf("\n");
}
for(i=0;i<5;i++)
{
L[i]=C[i]/w[i];
}
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
if(L[i]<L[j])
{
t=L[i];
L[i]=L[j];
L[j]=t;
t1=C[i];
C[i]=C[j];
C[j]=t1;
t2=w[i];
w[i]=w[j];
w[j]=t2;
t3=I[i];
I[i]=I[j];
I[j]=t3;
}
}
}
printf("\n The arranged data is");
printf("\n Item No\tCost\tWeight");
printf("\n......\t.........\t.........\n");
for(i=0;i<5;i++)
{
printf("%d\t\t%d\t\t%d",I[i],C[i],w[i]);
printf("\n");
}
for(i=0;i<5;i++)
{
if(w[i]<k)
{
W=W+C[i];
k=k-w[i];
}
else if(w[i]>k && k>0)
{
W=W+L[i]*k;
k=0;
}
else if(k==0)
{
break;
}
}
printf("\n The total cost is = %d",W);
getch();
return 0;
}
