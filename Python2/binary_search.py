#coding: utf-8

def binary_search(lista, value, first, last):
	result = 0
	mid = (first + last)/2
	lista.sort()
	if (value not in lista):
		result = 'Invalid'
	elif (lista[mid] == value):
		result = lista[mid]
	elif (lista[mid] > value):
		result = binary_search(lista, value, first, mid-1)
	else:
		result = binary_search(lista, value, mid+1, last)
	
	return result
