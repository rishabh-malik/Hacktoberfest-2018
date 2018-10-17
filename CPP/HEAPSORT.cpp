// C++ program for implementation of Heap Sort
#include <iostream>
using namespace std;
 
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
 
/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
// Driver program
int main()
{
    int arr[5],i;
    for(i=0;i<5;i++)
    {
    	cout<<"Input number=";
    	cin>>arr[i];
	}
	int n = sizeof(arr)/sizeof(arr[0]);
 
    heapSort(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);

}

//Best Case and Worst Case: -
//We're using a max heap represented as an array and inserting the max elements backwards into the back of our array, the worst case input for heapSort is any input that'll force us to reheapify every time we remove an element. This happens every time wheneverwe are trying to sort a set with no duplicates. It will still be ?(n log n).
//This property implies that heapSort's best-case is when all elements are equal and sorted (?(n), when we don't have to reheapify after every removal, which takes log(n) time since the max height of the heap is log(n)). But, the real best case for heapsort is ?(n log n),
//So, there's nothing much of a difference. 


//Time Complexity: - 
//"	Overall time complexity of Heap Sort is O(nLogn).
//"	Time complexity of heapify is O(Logn), and can also be called as (n-1) times.
//"	Time complexity of createAndBuildHeap() is O(n).


