#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int input, randomNumber;

	srand(time(0)); //generates new seed for pseudo-random number
	randomNumber = rand() % 100 + 1; // random number between 1 and 100

	cout << "Guess the number between 1 and 100" << endl;

	while(true)
    {
        cin >> input;

        if(input < 1 || input > 100)
        {
            cout << "input is not between 1 and 100!" << endl;
        }
        else if (input > randomNumber)
        {
            cout << "Random number is lower!" << endl;
        }
        else if (input < randomNumber)
        {
            cout << "Random number is higher!" << endl;
        }
        else if ( input == randomNumber)
        {
            cout << "You guessed it!" << endl;
            break;
        }
    }

	return 0;
}
