#!/usr/bin/env python3

cache = [1,1] + [None for i in range(0,998)]

def fibonacci(n):
	if cache[n] is None:
		cache[n] = fibonacci(n-1) + fibonacci(n-2)
	return cache[n]

if __name__ == '__main__':
	n = int(input("Enter a number: "))
	print("fib({}) = {}".format(n, fibonacci(n)))