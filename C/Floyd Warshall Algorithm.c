#include<stdio.h>
#include<conio.h>
#define v 4
#define inf 9999

int gra[v][v];
int cost[v][v];

void input()
{   
    int i,j,w;  
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {       
            if(i!=j)
            {
                printf("Input Weight of Edge from %d to %d : ",i+1,j+1);
                scanf("%d",&gra[i][j]);
            }
            if(i==j)
                gra[i][j]=0;        
        }
    }
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {       
            if(i!=j && gra[i][j]==0)
            {
                gra[i][j]=inf;
            }        
        }
    }
}

void Warshall()
{
    int i,j,k;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            cost[i][j]=gra[i][j];        
        }
    }
    for (k=0;k<v;k++) 
    { 
        for (i=0;i<v;i++) 
        { 
            for (j=0;j<v;j++) 
            { 
                if (cost[i][k] + cost[k][j] < cost[i][j]) 
                    cost[i][j] = cost[i][k] + cost[k][j]; 
            } 
        } 
    } 
}

void disp()
{
    int i,j;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(cost[i][j]==inf)
                printf("INF\t");
            else
            printf("%d\t",cost[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    input();
    Warshall();
    disp();
    return 0;
}

