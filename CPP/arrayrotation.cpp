#include <bits/stdc++.h>

using namespace std;

void rot(int arr[],int d,int n)
{
    int temp[n];
    for(int i=0;i<n;i++)
    {
        temp[(i+d)%n]=arr[i];
    }
    for(int i=0;i<n;i++)
        cout<<temp[i]<<" ";
}

int main()
{
    int arr[]={1,5,2,3,5,4,2,3,4,5,5,5};
    int n=(sizeof(arr)/sizeof(arr[0]));
    int d=3;
    rot(arr,d,n);
}
