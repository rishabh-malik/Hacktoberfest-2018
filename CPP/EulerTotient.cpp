#include <iostream>

using namespace std;

//Find how many numbers smaller than n are coprime with n
long long eulerTotient(long long n)
{
	long long result = n;

	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			while(n % i == 0)
			{
				n /= i;
			}
			result -= result / i;
		}
	}

	if(n > 1)
	{
		result -= result / n;
	}

	return result;
}

int main()
{
	long long n;
	cout << "Please enter a number: " << flush;
	cin >> n;
	cout << "Euler totient of " << n << " is " << eulerTotient(n) << endl;

	return 0;
}
