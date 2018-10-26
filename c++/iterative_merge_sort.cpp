#include<iostream>
using namespace std;

void mergesort(int array[],int n)
{
	int k = 1,i,j,size2;
	int *c = new int[n];
	int a,b,m;
	while(k<n)
	{
		for(i=0;i<n;i+=2*k)
		{
			j=i+k;
			if(j>n)
				break;
			size2 = min(j+k,n);		//second window from j to size2-1

			a = i;
			b = j;
			m=0;
			while(a<i+k&&b<size2)
			{
				if(array[a]<=array[b])
				{
					c[m++] = array[a++];
				}
				else
				{
					c[m++] = array[b++];					
				}
			}
			while(a<i+k)
			{
				c[m++] = array[a++];
			}
			while(b<size2)
			{
				c[m++] = array[b++];
			}

			for(a=0;a<m;a++)
			{
				array[i+a] = c[a];
			}
		}

		k*=2;
	}
}

int main()
{
	int n,i;
	cout<<"How many numbers : ";
	cin>>n;
	int *a = new int[n];
	for(int i = 0;i<n;i++)
		cin>>a[i];

	mergesort(a,n);

	cout<<"Sorted ans. is : ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}

	return 0;
}