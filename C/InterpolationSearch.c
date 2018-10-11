// C Program to do Interpolation Search
#include<stdio.h>

int interpolation(int input_arr[], int n, int x){
  int low=0, high=(n-1);
  int pos;
  while(low<=high && x>=input_arr[low] && x<=input_arr[high]){
    //Finding the position of search item keeping the order in mind
    pos=low+(((double)(high-low)/(input_arr[high]-input_arr[low]))*(x-input_arr[low]));

    if(input_arr[pos]==x)
      return pos;

    if(input_arr[pos]<x)
      low=pos+1;

    else
      high=pos-1;
  }
  return -1;
}

int main()
{
  int arr[] =  {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    int x = 24; // Element to be searched 
    int index = interpolation(arr, n, x); 
  
    // If element was found 
    if (index != -1) 
        printf("Element found at index %d", index); 
    else
        printf("Element not found."); 
  return 0;
}
	     
  

