import java.util.Arrays;

/**
 * Merge sort is based on the divide-and-conquer principle. The algorithm
 * consists of recursively dividing the unsorted list in the middle, sorting
 * each sublist, and then merging them into one single sorted list.
 * 
 * - COMPLEXITY: O(nlog(n)) 
 * - IN-PLACE: No 
 * - STABLE: Yes
 * 
 */
public class MergeSort<T extends Comparable<T>> {

	/**
	 * This method sorts an array. The array must not contain null elements. If
	 * leftIndex and/or rightIndex are outside the array limits, this method will do
	 * absolutely nothing. It implements the merge sort strategy.
	 * 
	 * @param array The target array of the sorting algorithm.
	 * 
	 */
	public void sort(T[] array) {
		this.sort(array, 0, array.length - 1);
	}

	/**
	 * This method sorts an interval of the array, starting at leftIndex and ending
	 * at rightIndex, both inclusive. The array must not contain null elements. If
	 * leftIndex and/or rightIndex are outside the array limits, this method will do
	 * absolutely nothing. It implements the merge sort strategy.
	 * 
	 * @param array      The target array of the sorting algorithm.
	 * @param leftIndex  The index where the sorting should begin.
	 * @param rightIndex The index where the sorting should end.
	 * 
	 */
	public void sort(T[] array, int leftIndex, int rightIndex) {

		if (this.inputValidation(array, leftIndex, rightIndex)) {
			int middleIndex = (leftIndex + rightIndex) / 2;

			this.sort(array, leftIndex, middleIndex);
			this.sort(array, middleIndex + 1, rightIndex);

			this.merge(array, leftIndex, middleIndex, rightIndex);
		}
	}

	/**
	 * This method validates all the parameters received by the sort method. The
	 * array received must not be null or contain less than two elements. Also, the
	 * index parameters given may be suitable to the array.
	 * 
	 * @param array      The target array of the sorting algorithm.
	 * @param leftIndex  The index where the sorting should begin.
	 * @param rightIndex The index where the sorting should end.
	 * 
	 * @return the boolean that represents the prameter's validity.
	 * 
	 */
	private boolean inputValidation(T[] array, int leftIndex, int rightIndex) {
		boolean isValid = true;

		// A null can't be sorted.
		if (array == null) {
			isValid = false;
		}

		// Arrays containing less than two elements don't need to be sorted.
		else if (array.length < 2) {
			isValid = false;
		}

		else {
			// Prevent misuse of indexes parameters.
			if (leftIndex > rightIndex) {
				isValid = false;
			}

			// Prevent attempts to access invalid indexes.
			if (leftIndex < 0) {
				isValid = false;
			}

			if (rightIndex < 0) {
				isValid = false;
			}

			if (rightIndex > (array.length - 1)) {
				isValid = false;
			}
		}

		return isValid;
	}

	/**
	 * Using a copy of the original array and the assumption that each half of the
	 * array is already sorted, this method will sort the entire array by comparing
	 * the elements of distinct halves, putting the proper element at its position
	 * in the original array.
	 * 
	 * @param array       The target array of the sorting algorithm.
	 * @param leftIndex   The index where the sorting should begin.
	 * @param middleIndex The index that divides the two halves.
	 * @param rightIndex  The index where the sorting should end.
	 * 
	 */
	private void merge(T[] array, int leftIndex, int middleIndex, int rightIndex) {
		T[] copy = Arrays.copyOf(array, array.length);

		int i = leftIndex;
		int j = leftIndex;
		int k = middleIndex + 1;

		while ((i <= middleIndex) && (k <= rightIndex)) {
			if (copy[i].compareTo(copy[k]) < 0) {
				array[j] = copy[i];
				i++;
			} else {
				array[j] = copy[k];
				k++;
			}
			j++;
		}

		while (i <= middleIndex) {
			array[j] = copy[i];
			i++;
			j++;
		}

		while (k <= middleIndex) {
			array[j] = copy[k];
			j++;
			k++;
		}
	}

}
