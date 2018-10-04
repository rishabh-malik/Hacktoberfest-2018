function bubbleSort(array: number[]): number[] {
  console.log("Before Sotr: ", array);
  for (let i = 0; i < array.length; i++) {
    for (let j = 0; j < array.length - 1; j++) {
      if (array[j] > array[j + 1]) {
        let tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
      }
    }
  }
  console.log("After Sort: ", array);
  return array;
}

bubbleSort([20, 15, 36, 45, 2, 9, 0]);
