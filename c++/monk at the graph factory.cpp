/*
Problem to determine if a given graph is a tree or not.
Problem Statement: Our Code Monk recently learnt about Graphs and is very excited!  
He went over to the Graph-making factory to watch some freshly prepared graphs.  
Incidentally, one of the workers at the factory was ill today, so Monk decided to step in and do her job.  
The Monk's Job is to Identify whether the incoming graph is a tree or not.  
He is given N, the number of vertices in the graph and the degree of each vertex.  
Find if the graph is a tree or not.

Input:
First line contains an integer N, the number of vertices.
Second line contains N space-separated integers, the degrees of the N vertices.
/*

#include<bits/stdc++.h>
using namespace std;
 
int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    	freopen("error.txt", "w", stderr);
	#endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,d,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>d;
		sum+=d;
	}
	if(sum==2*n-2)
		cout<<"Yes";
	else
		cout<<"No";
}
