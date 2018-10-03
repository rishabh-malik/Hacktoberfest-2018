class BinarySearch
{
    // find out if a key x exists in the sorted array A using iterative binary search algorithm
    public static int binarySearch(int[] A, int x)
    {
        
        int left = 0, right = A.length - 1;

        
        while (left <= right)
        {
            // we find the mid value in the search space and compare it with key value

            int mid = (left + right) / 2;

            /* overflow can happen. Use:
             int mid = left + (right - left) / 2;
             int mid = right - (right - left) / 2; */

            // key value is found
            if (x == A[mid]) {
                return mid;
            }

            // discard all elements in the right search space including the mid element
            else if (x < A[mid]) {
                right = mid - 1;
            }

            // discard all elements in the left search space
            // including the mid element
            else {
                left = mid + 1;
            }
        }

        // x doesn't exist in the array
        return -1;
    }

    public static void main(String[] args)
    {
        int[] A = {1, 4, 9, 16, 25, 36};
        int key = 4;

        int index = binarySearch(A, key);

        if (index != -1) 
	{
		System.out.println("Element found at index " + index);
	} 
	
	else 
	{
		System.out.println("Element not found in the array");
	}
    }
}
