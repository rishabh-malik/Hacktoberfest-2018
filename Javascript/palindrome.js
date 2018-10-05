function palindrome(x) {
    x = x.toLowerCase();    //Converts the string to lowercase.
    var y = x.split('').reverse().join('');     //Creates an array, reverses it and then joins it.
    if (y === x) {          //Checks whether they are equal or not.
        console.log('Its a palindrome');
        }
    else {
        console.log('Not a Palindrome');
        }
    }


palindrome("Racecar");      //Function called.
