/**
 * This algorithm applies a modified bubble sort. At first, it will iterate over
 * the array comparing elements separated by a gap (size / 1.25), swapping them
 * when they're out of increasing order. After the first iteration the gap will
 * be reduced by 1.25 and the comparisons will restart. The last iteration must
 * compare adjacent elements. It optimizes the bubble sort algorithm by dealing
 * easily with the small elements near to the end of the array, that kind of
 * situations have a huge impact at the time of the algorithm.
 * 
 * - COMPLEXITY: O(n2)
 * - IN-PLACE: Yes
 * - STABLE: Yes
 * 
 * @author Matheus Alves dos Santos
 * 
 */
public class CombSort<T extends Comparable<T>> {

	/**
	 * This method sorts an array. The array must not contain null elements. If
	 * leftIndex and/or rightIndex are outside the array limits, this method will do
	 * absolutely nothing. It implements the comb sort strategy.
	 * 
	 * @param array      The target array of the sorting algorithm.
	 * 
	 */
	public void sort(T[] array) {
		this.sort(array, 0, array.length - 1);
	}

	/**
	 * This method sorts an interval of the array, starting at leftIndex and ending
	 * at rightIndex, both inclusive. The array must not contain null elements. If
	 * leftIndex and/or rightIndex are outside the array limits, this method will do
	 * absolutely nothing. It implements the comb sort strategy.
	 * 
	 * @param array      The target array of the sorting algorithm.
	 * @param leftIndex  The index where the sorting should begin.
	 * @param rightIndex The index where the sorting should end.
	 * 
	 */
	public void sort(T[] array, int leftIndex, int rightIndex) {
		if (this.inputValidation(array, leftIndex, rightIndex)) {
			int size = rightIndex - leftIndex + 1;
			boolean swapped = true;
			int gap = size;

			while (gap > 1 || swapped) {
				if (gap > 1) {
					gap = (int) (gap / 1.25);
				}

				int i = leftIndex;
				swapped = false;

				while (i + gap <= rightIndex) {
					if (array[i].compareTo(array[i + gap]) > 0) {
						this.swap(array, i, (i + gap));
						swapped = true;
					}

					i++;
				}
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
