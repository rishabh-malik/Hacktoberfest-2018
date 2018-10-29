//Should've made strip containing points from both the sections, this one is not nlogn

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct point{
	int x,y;
};
double min(double a,double b)
{
	if(a<b)
		return a;
	return b;
}
int cx(point a,point b)
{
	return a.x<=b.x;
}
int cy(point a,point b)
{
	return a.y<=b.y;
}

double dist(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double closestpair(point x[],int n,point y[])
{
	if(n==2)
		return dist(x[0],x[1]);
	if(n<2)
		return 100000000;

	point yl[n],yr[n];

	int i,j=0,k=0;

	for(i=0;i<n;i++)
	{
		if(y[i].x<x[n/2].x)
		{
			yl[j++] = y[i];
		}
		else if(y[i].x>x[n/2].x)
		{
			yr[k++] = y[i];
		}
		else if(j<k)
		{
			yl[j++] = y[i];
		}
		else
		{
			yr[k++] = y[i];	
		}

	}

	double m1 = closestpair(x,j,yl);
	double m2 = closestpair(x+j,k,yr);

	double m3 = min(m1,m2);

	point strip[n];
	j=0;
	for(i=0;i<k;i++)
	{
		if(yr[i].x-x[n/2].x<=m3)
		{
			strip[j++] = yr[i]; 
		}
	}

	for(i=n/2-1;i>=0&&x[n/2].x-x[i].x<=m3;i--)
	{
		for(k=0;k<j&&strip[k].y-x[i].y<=m3;k++)
		{	

			if(dist(strip[k],x[i])<m3&&dist(strip[k],x[i])!=0)
				m3 = dist(strip[k],x[i]);

		}

	}

	return m3;

}

int main()
{
	int n,i;
	cin>>n;
	point px[n],py[n];
	for(i=0;i<n;i++)
	{
		cin>>px[i].x>>px[i].y;
		py[i] = px[i];
	}

	sort(px,px+n,cx);
	sort(py,py+n,cy);

	double m=closestpair(px,n,py);

	cout<<m;

	return 0; 


}