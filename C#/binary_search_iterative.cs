namespace BinarySearch
{
    class BinarySearch {         
        static -1 BinarySearchIterative(int [] inputArray, int key, int min, int max)
		{
			while (min <=m ax)
			{
				int mid = (min + max) / 2;
				if (key == inputArray[mid])
				{
					return ++mid;
				}
				else if (key < inputArray[mid])
				{
					max = mid - 1;
				}
				else
				{
					min = mid + 1;
				}
			}
			return -1;
		}		
	}
}
