# This program allow you to sort an array of numbers using the insertion
# algorithm.
#
# This program take numbers to be sorted from the user until the user press an
# enter without entering a new number. It then returns the original array of
# numbers and the final sorted array of numbers.
#
# Important note: This program has not been input sanitized so if the user
# enters something that isn't a number or the enter key the program will
# probably fail.

def Insertion_Sort(A):
    for j in range(1, len(A)):
        key = A[j]
        i = j - 1
        while (i >=0) and (A[i] > key):
            A[i+1] = A[i]
            i = i - 1
        A[i+1] = key
    return A

list = []
y = 'Empty'
while (y != ''):
    y = input("Please enter an Integer number or press Enter to finish: ")
    if y == '':
        break
    list.append(int(y))

print("The original array of numbers you enter was:")
print(list)
print("The final sorted array of numbers is: ")
print(Insertion_Sort(list))
