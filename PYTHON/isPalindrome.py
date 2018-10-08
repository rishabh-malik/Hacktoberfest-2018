def isPalindrome():
	my_str = input("Enter a word: ")
	my_str = my_str.casefold() #ignore cases
	
	rev_str = reversed(my_str)
	if list(my_str) == list(rev_str):
		print("It's a palindrome")
	else:
		print("It's not a palindrome")
