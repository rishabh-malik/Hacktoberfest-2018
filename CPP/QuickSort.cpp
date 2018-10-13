#include<bits/stdc++.h>
using namespace std;
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b=temp;
}
int partition(int a[],int start, int end){
    int pivot = a[end];
    int i =start-1;
    int temp;
    for(int j=start;j<end;j++){
        if(a[j]<=pivot){
             i++;
            swap(a[i],a[j]);
           
        }
    }
    swap(a[i+1],a[end]);
    return i+1;
}
void quick(int a[],int start, int end){
  if(start<end){
      int part = partition(a,start,end);
      quick(a,start,part-1);
      quick(a,part+1,end); 
  }
}
void print(int a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Initial Array : "<<"\n";
    print(a,n);
    cout<<"\n";
    quick(a,0,n-1);
    cout<<"Array after Quick sort : "<<"\n";
    print(a,n);
    
}
