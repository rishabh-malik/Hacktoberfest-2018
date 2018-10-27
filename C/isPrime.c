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
	
	/* Check if prime. */
	if ( isPrime(atol(argv[1])) ) /* atoi returns 0 if string is not a number.*/
	{
		printf("%s is a prime number.\n", argv[1]);
	}
	else
	{
		/* TODO: Add error messages for specific invalid input. Right now there is only a generic message for all errors. */
		printf("%s is not a prime number\n", argv[1]);
	}

	return 0;
} /* End main */

/* Function definition.*/
int isPrime(long number)
{
	/* TODO: Add range checking for very big numbers (platform dependent). */
	long iter = 2;
	if (number < 2)
	{
		return 0; /* Placeholder value. */
	}
	else
	{
		/* Super, super, super inneficient method... */
		while (iter * iter <= number)
		{
			if (number % iter++ == 0)
			{
				return 0; /* Not a prime number. */
			}
		}
		return 1; /* Is prime number. */
	}
} /* End isPrime */