//Tabularization

#include<iostream>
using namespace std;

void matrix(int p[],int n,int table1[100][100],int table2[100][100])
{	int i,j,len,temp,min,k;
	//Initialize table 1
	for(i=0;i<n;i++)
	{
		table1[i][i] = 0;
		table2[i][i] = i;		
	}

	for(len = 2;len<=n;len++)
	{
		for(i=0;i<=n-len;i++)
		{
			j = i+len-1;
			min = 100000000;
			for(k=i;k<j;k++)
			{
				temp = table1[i][k]+table1[k+1][j]+p[i]*p[k+1]*p[j+1];
				if(temp<min)
				{
					table2[i][j] = k;
					min = temp;
				}
			}

			table1[i][j] = min;
		}
	}


}

void printer(int table2[100][100],int i,int j)
{	
	if(i==j)
	{
		cout<<"A"<<i+1;
		return;
	}


	cout<<"(";
	printer(table2,i,table2[i][j]);
	cout<<")(";
	printer(table2,table2[i][j]+1,j);
	cout<<")";
}


int main()
{
	int n,i,j;
	int table1[100][100],table2[100][100];
	cin>>n;
	int p[n+1];
	for(i=0;i<n+1;i++)
		cin>>p[i];

	matrix(p,n,table1,table2);

	cout<<"Ans : "<<table1[0][n-1]<<"\n";

	/*for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<table1[i][j]<<" ";
		cout<<"\n";
	}*/

	printer(table2,0,n-1);
	return 0;
}