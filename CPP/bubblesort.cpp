#include <iostream>
using namespace std;

void bubblesort(int n, int arr[])
{
  for(int i = 0; i < n-1; i++){
    for(int j = n-1; j > i; j--){
      if(arr[j-1] > arr[j]){
        int temp = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main()
{
  int n = 5;
  int arr[] = {2, 1, 4, 3, 5};

  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;

  bubblesort(n, arr);
  
  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
