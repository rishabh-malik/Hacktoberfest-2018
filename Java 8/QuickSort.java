/**
 * Quicksort is based on the divide-and-conquer paradigm. The algorithm chooses
 * a pivot element and rearranges the elements of the interval in such a way
 * that all elements lesser than the pivot go to the left part of the array and
 * all elements greater than the pivot, go to the right part of the array. Then
 * it recursively sorts the left and the right parts.
 * 
 * - COMPLEXITY: O(n2) 
 * - IN-PLACE: Yes 
 * - STABLE: No
 * 
 */
public class QuickSort<T extends Comparable<T>> {

	/**
	 * This method sorts an array. The array must not contain null elements. If
	 * leftIndex and/or rightIndex are outside the array limits, this method will do
	 * absolutely nothing. It implements the quick sort strategy.
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
	 * absolutely nothing. It implements the quick sort strategy.
	 * 
	 * @param array      The target array of the sorting algorithm.
	 * @param leftIndex  The index where the sorting should begin.
	 * @param rightIndex The index where the sorting should end.
	 * 
	 */
	public void sort(T[] array, int leftIndex, int rightIndex) {
		// Only arrays that go through all validations will be sorted.
		if (this.inputValidation(array, leftIndex, rightIndex)) {
			int pivotIndex = partition(array, leftIndex, rightIndex);

			this.sort(array, leftIndex, pivotIndex - 1);
			this.sort(array, pivotIndex + 1, rightIndex);
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
	 * After choosing a pivot element, the one at the leftIndex, this method will
	 * reorder the array so that all elements with values less or equal than the
	 * pivot come before it, while all elements with values greater than the pivot
	 * come after it. After this partitioning, the pivot is in its final position.
	 * 
	 * @param array      The target array of the sorting algorithm.
	 * @param leftIndex  The index where the sorting should begin.
	 * @param rightIndex The index where the sorting should end.
	 * 
	 * @return the pivot's final position.
	 * 
	 */
	private int partition(T[] array, int leftIndex, int rightIndex) {
		T pivot = array[leftIndex];

		int i = leftIndex;

		for (int j = i + 1; j <= rightIndex; j++) {
			if (array[j].compareTo(pivot) <= 0) {
				i++;
				this.swap(array, i, j);
			}
		}

		this.swap(array, leftIndex, i);
		return i;
	}

	/**
	 * Swaps the contents of two positions in an array.
	 *
	 * @param array The array to be modified.
	 * @param i     One of the target positions.
	 * @param j     The other target position.
	 */
	private void swap(T[] array, int i, int j) {
		T aux = array[i];
		array[i] = array[j];
		array[j] = aux;
	}
}
