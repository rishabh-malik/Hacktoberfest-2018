#include <iostream>
using namespace std;

int searchIndex(int arr[],int low, int high, int x){
    if(low<=high){
        int mid=(low+(high-low))/2;

        if (arr[mid]==x){
            return mid;
        }
        if(x>arr[mid]){
            return searchIndex(arr, mid+1, high, x);
        }
        else
         return searchIndex(arr, low, mid-1, x);

    }
    return -1;
}

int main()
{
    int arr[]={1, 3, 5, 5, 5, 7 ,28, 37, 42};
    int low,high,k;
    int n = sizeof(arr);
    cout<<"Enter the element to be searched"<<endl;
    cin>>k;

    int result = searchIndex(arr,0,n-1,k);

    if (result == -1)
    cout<<"Not found"<<endl;
  else
    cout<<"Element is found at index "<<result<<endl;
    return 0;
}