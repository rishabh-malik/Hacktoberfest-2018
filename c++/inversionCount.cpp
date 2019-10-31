/*******************************************8
INVERSION COUNT
You are given an array A find out number of pairs (i,j) in array A such that A[i] > A[j] and i < j.


Input Format:
The first line consists of number of test cases t. Each test case consists of integer N followed by N space separated integers.

Constraints:
1 <= N <= 100000
1 <= t <= 20
0 <= A[i] <= 100000000

Output Format:
The number of inversions in array

Sample Input:
2
4
1 2 4 3
3
3 2 1
Sample Output:
1
3
Time Limit: 2 sec

*********************************************************/


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll merge(ll arr[],ll start,ll end){

    ll mid= (start+end)/2;
    ll i=start;
    ll j=mid+1;
    ll temp[end-start+1]={0};
    ll k=0;
    ll ans=0;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            ans= ans + mid-i+1;

        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=end){
        temp[k++]=arr[j++];
    }
    i=0;
    for(ll k=start;k<=end;k++){
        arr[k]=temp[i++];
    }
    return ans;

}


ll inversionCout(ll arr[],ll start,ll end){

    if(start>=end){
        return 0;
    }
     ll mid=(start+end)/2;

     ll ans=inversionCout(arr,start,mid);
     ans += inversionCout(arr,mid+1,end);

     ans += merge(arr,start,end);

     return ans;
}

int main(){

 ll t;
 cin>>t;
 while(t--){
     ll n;
     cin>>n;
     ll arr[n];
     for(ll i=0;i<n;i++){
         cin>>arr[i];
     }
     cout<<inversionCout(arr,0,n-1)<<endl;
 }

  return 0;
}
