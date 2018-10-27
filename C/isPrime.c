#include <stdio.h>
#include <stdlib.h>

/* Function declaration. */
int isPrime(long number);

/* Main function body. */
int main(int argc, char *argv[])
{
	long numberToCheck = 0;

	if (argc < 2) /* First argument is the program name (argv[0]), which is "main". */
	{
		printf("Not enough arguments.\n");
		return 1;
	}

	/* TODO: Add error messages for specific invalid input. Right now there is only a generic message for all errors. */
	/* Check if prime. */
	if ( isPrime(atol(argv[1])) ) /* atoi returns 0 if string is not a number.*/
	{
		printf("%s is a prime number.\n", argv[1]);
	}
	else
	{
		printf("%s is not a prime number or it may be invalid (not a number or higher than LONG_MAX).\n", argv[1]);
	}

	return 0;
} /* End main */

/* Function definition.*/
int isPrime(long number)
{
	if (number < 2)
	{
		return 0; /* Placeholder value. */
	}
	else
	{
		return 1; /* Placeholder value. */
	}
} /* End isPrime */