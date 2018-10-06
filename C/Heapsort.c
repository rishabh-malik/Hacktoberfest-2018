#include<stdio.h>
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;
		heapify(arr, n, largest);
	}
}
void Buildmax_heap(int arr[], int n){
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}
void heapSort(int arr[], int n)
{   int i;
    Buildmax_heap(arr,n);
	for (i=n-1; i>=0; i--)
	{
		int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n)
{int i;
	for (i=0; i<n; ++i)
		printf("%d ",arr[i]);
	printf("\n");
}

int main()
{
	int n,i;
	printf("Enter the size of array to sort:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements of array:");
	for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
	heapSort(arr, n);
	printf("\nSorted array is: \n");
	printArray(arr, n);
return 0;
}
