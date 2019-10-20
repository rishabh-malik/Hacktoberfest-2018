/*PROBLEM STATMENT :
You have been given an integer array A and a number K.  
Now, you need to find out whether any two different elements of the array A sum to the number K.  
Two elements are considered to be different if they lie at different positions in the array.  
If there exists such a pair of numbers, print "YES" (without quotes), else print "NO" without quotes.
*/

#include<bits/stdc++.h>
using namespace std;
 
bool sum(long a[], long k, long n){
	for(int i=0,j=n-1;i<j;){
		if(a[i]+a[j]<k)
			i++;
		else if(a[i]+a[j]>k)
			j--;
		else
			return true;
		

	}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    	freopen("error.txt", "w", stderr);
	#endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long n,k;
	cin>>n>>k;
	long ar[n];
	
	for(int i=0;i<n;i++)
		cin>>ar[i];

	sort(ar,ar+n);

	if(!sum(ar,k,n))
		cout<<"NO";
	else
		cout<<"YES";
}
