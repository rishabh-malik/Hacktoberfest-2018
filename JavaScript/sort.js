function sort(arr) {
	var tmp;
	for (var i = 0; i < arr.length; i++) {
		for (var j = i; j > 0; j--) {
			if (arr[j] < arr[j-1]) {
				tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}
		}
	}
	return arr;
}

console.log(sort([1,9,2,15,7,12,6,1,36,8,19]));
