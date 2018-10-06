/**
 * This algorithm applies two bubblesorts simultaneously. In a same iteration, a
 * bubblesort pushes the greatest elements to the end of the array and another
 * bubblesort pushes the smallest elements to the beginning of the array. At the
 * end of the first iteration, the smallest element is in the first position
 * (index 0) and the greatest element is the last position (index N-1). The next
 * iteration does the same from index 1 to index N-2. This process continues
 * until the array is completely sorted.
 * 
 * - COMPLEXITY: O(n2)
 * - IN-PLACE: Yes
 * - STABLE: Yes
 * 
 */
public class CocktailSort<T extends Comparable<T>> {

	/**
	 * This method sorts an array. The array must not contain null elements. If
	 * leftIndex and/or rightIndex are outside the array limits, this method will do
	 * absolutely nothing. It implements the cocktail sort strategy.
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
	 * absolutely nothing. It implements the cocktail sort strategy.
	 * 
	 * @param array      The target array of the sorting algorithm.
	 * @param leftIndex  The index where the sorting should begin.
	 * @param rightIndex The index where the sorting should end.
	 * 
	 */
	public void sort(T[] array, int leftIndex, int rightIndex) {
		if (this.inputValidation(array, leftIndex, rightIndex)) {
			int startAt = leftIndex;
			int endAt = rightIndex;
			int middleIndex = 1 + ((leftIndex + rightIndex) / 2);

			for (int i = leftIndex; i <= middleIndex; i++) {
				for (int j = startAt; j < endAt; j++) {
					if (array[j].compareTo(array[j + 1]) > 0) {
						this.swap(array, j, j + 1);
					}
				}
				endAt--;

				for (int j = endAt; j > startAt; j--) {
					if (array[j].compareTo(array[j - 1]) < 0) {
						this.swap(array, j, j - 1);
					}
				}
				startAt++;
			}
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
