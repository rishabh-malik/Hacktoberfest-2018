var x = 'Hacktober fest';

function longestWord(x) {
    var arr = [];
    arr = x.split(' '); //dont use split('') as it will split it in characters, use split(' ') so that it splits them whenever ' ' comes.
    var long = arr[0];
    for (var i = 0; i < arr.length; i++) {
        if (arr[i].length > long.length) {
            long = arr[i];
        }
    }
    return(long);     //Returns the longest word.
}
        
console.log(longestWord(x));    //Function called.
