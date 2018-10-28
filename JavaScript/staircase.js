function staircase(n) {
    let line = Array(n).fill(' ');
    for (var i = n-1; i >= 0; i--) {
        line[i] = '#';
        console.log(line.join(''));
    }
}
