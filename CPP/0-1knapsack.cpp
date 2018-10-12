#include<bits/stdc++.h>
                using namespace std;
	int main()
                {int n,m;	//items,  weight;
	int weight[100],profit[100];
	int dp[100][100];
	cout<<"enter no. of items\n";
	cin>>n;
	cout<<"enter total capacity of knapsack\n";
	cin>>m;
	for(int i=1;i<=n;i++)
	cin>>weight[i];
	for(int i=1;i<=n;i++)
	cin>>profit[i];
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
	for(int j=0;j<=m;j++){dp[i][j]=0;
			if(weight[i]<=j)
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+profit[i]);
	}}cout<<"Profit is "<<dp[n][m];}

