function fact(x) {
  if(x==0) {
     return 1;
  }
  return x * fact(x-1);
}

console.log('Factorial of 5 is =>', fact(5));