function prime(n) {             //The function returns true if the number is a prime else it returns false.
    var i;
    if (n <= 1) {
        return false;               //It checks the numbers till 5 using simple if else statements to reduce the time complexity.
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 === 0 || n % 3 === 0) {
        return false;
    }
    for (i = 5; i < n; i++) {           //Loop to check if the number is a prime.
        if (n % i === 0) {
            return false;
        }
        else {
            return true;
        }
    }
}

console.log(prime(11));         //Function Called.
