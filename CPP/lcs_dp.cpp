#include<iostream>
#include<cstring>
#include<cstdlib>
#define len 100
using namespace std;
int dp[len][len];
int max(int a,int b)
{return (a>b)?a:b;}
char *lcs(char *x,char *y)
{int i,j;
int n,m;
char a[50];
	n=strlen(x);
	m=strlen(y);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{dp[i][j]=0;
    if(x[i-1]==y[j-1])
    dp[i][j]=1+dp[i-1][j-1];
    else
    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    } i=n;j=m;
	char *str=(char *)malloc ((len+1)*sizeof(char));
	int g=dp[n][m];
	str[g--]='\0';
	while(i && j)
	{if(x[i-1]==y[j-1])
		{str[g--]=x[i-1];
			i--;j--;
		}else if(dp[i-1][j]>dp[i][j-1])
			i--;
			else j--;}
return str;}
int main()
{char x[len],y[len];
	int i,j,n;
	cout<<"enter string \n";
	cin>>n;
	cin>>x>>y;
	char *str=lcs(x,y);
	for(i=3;i<=n;i++)
	{cin>>y;
str=lcs(str,y);}
cout<<str;
return 0;
}

