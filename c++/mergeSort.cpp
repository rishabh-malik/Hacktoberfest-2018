//This program requires the user to input the number of numbers that need to be sorted.
//The next line of input is the list of numbers to be sorted.
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::endl;

void merge(int arr[], int p, int q, int r);
void mergeSort(int arr[], int a, int b)
{
	if (a < b)
	{
		int mid = (a + b) / 2;
		mergeSort(arr, a, mid);
		mergeSort(arr, mid + 1, b);
		merge(arr, a, mid, b);
	} 
}

int n;

void merge(int arr[], int p, int q, int r)
{
	int ar1[q - p + 1];
	int ar2[r - q];
	for (int i = 0; i < (q-p+1); ++i)
	{
		ar1[i] = arr[p + i - 1];
	}
	for (int i = 0; i < (r - q); ++i)
	{
		ar2[i] = arr[q + i];
	}
	
	int i = 1, j = 1;
	for (int k = p; k <= r; ++k)
	{
		if (i > (q - p + 1))
		{
			while (j <= (r - q))
			{
				arr[p + (i + j) - 3] = ar2[j - 1];
				++j;
			}
		} else if (j > (r - q))
		{
			while (i <= (q - p + 1))
			{
				arr[p + (i + j) - 3] = ar1[i - 1];
				
				++i;
			}
		} else if (ar1[i - 1] < ar2[j - 1])
		{
			arr[k - 1] = ar1[i - 1];
			++i;
		} else {
			arr[k - 1] = ar2[j - 1];
			++j;
		}
	}
}

int main(void)
{
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	mergeSort(arr, 1, n);
	for (auto c : arr)
	{
		cout << c << " ";
	}
	cout << endl;
}