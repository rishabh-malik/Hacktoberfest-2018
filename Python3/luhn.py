#!/usr/bin/env python3

'''

Program:    luhn.py
Purpose:    Calculate the check digit of a credit card 
                or bank account number -- assuming it uses
                the Luhn algorithm
Reference:  https://en.wikipedia.org/wiki/Luhn_algorithm
Usage:      ./luhn.py <Card Number except the last digit>
Example:    ./luhn.py 5500 0000 0000 000

'''

import sys

def luhn(number):
    
    # Flag to track whether we're looking at an odd or even digit
    oddDigit = True

    # Store temporary values as the algorithm progresses
    total = 0

    # Loop through string from back to front
    for n in reversed(number):

        # Convert digit from string to int
        n = int(n)

        if oddDigit:
            # Double the digit -- if sum is greater than 9, then subtract
            #   9 before adding it to the total
            if n < 5:
                total += (2 * n)
            else:
                total += ((2 * n) - 9)
            oddDigit = False
        else:
            # Add digit to total with no modification
            total += n
            oddDigit = True

    return ((total * 9) % 10)

def main():

    # Concatenate all command line arguments (user input may contain spaces)
    raw_number = ""
    for i in range(1, len(sys.argv)):
        raw_number += sys.argv[i]

    # Run the number through the algorithm and display the result
    checkDigit = luhn(raw_number)
    print("The check digit is: %d" % checkDigit)

if __name__ == "__main__":
    main()
