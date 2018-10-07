#include<iostream>

using namespace std;

int main()
{
    int sum, product, average, num1, num2, num3;

    cout << "Num1: ";
    cin >> num1;
    cout << "Num2: ";
    cin >> num2;
    cout << "Num3: ";
    cin >> num3;

    sum = num1 + num2 + num3;
    product = num1 * num2 * num3;
    average = sum / 3.0;

    cout << "Sum = " << sum << endl;
    cout << "Product = " << product << endl;
    cout << "Average = " << average << endl;

    return 0;
}
