#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **p;
	int m,n;
	int i,j,l,q,t=0,d=0,k;
	printf("enter the value of m and n");
	scanf("%d %d",&m,&n);
	p=(int **)malloc(m*sizeof(int *));
	for(i=0;i<m;i++)
	{
		p[i]=(int *)malloc(n*sizeof(int));
	}
	printf("enter elements to the array\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&p[i][j]);
		}
	}
	for(i=0;i<m;i++)
	{
		if((i+1)%2!=0)
		{
			//printf("reaching1");
			for(j=1;j<n;j++)
			{
				for(k=0;k<n-j;k++)
				{
					if(p[i][k]>p[i][k+1])
					{
						t=p[i][k];
						p[i][k]=p[i][k+1];
						p[i][k+1]=t;
					}
				}
			}
		}
		else
		{
			for(l=1;l<n;l++)
			{
				for(q=0;q<n-l;q++)
				{
					if(p[i][q]<p[i][q+1])
					{
						d=p[i][q];
						p[i][q]=p[i][q+1];
						p[i][q+1]=d;
					}
				}
			}
		}
	}
	printf("The final matrix by arranging odd rows in ascending order and even rows in descending order\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}
}
