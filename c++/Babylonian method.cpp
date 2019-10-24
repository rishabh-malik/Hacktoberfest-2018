#include <cmath>
#include <random>
#include <iostream>

//Possibly the first algorithm ever invented by human to calculate the square root of a positive number, known as Babylonian
//method (https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Babylonian_method), is implemented by this function.

double BabylonianSqrt(double num, double relativeAccuracy, double initialGuess)
{
    double root{ initialGuess };
    while (true)
    {
        if (root * root <= num && root * root * (1 + relativeAccuracy) * (1 + relativeAccuracy) > num)
            return root;
        if (root * root >= num && num && root * root * (1 - relativeAccuracy) * (1 - relativeAccuracy) < num)
            return root;
        
        root = (root + num / root) / 2;
    }
}

//Driver Program to test above function
int main()
{
    std::mt19937 randomEngine(std::random_device{}());
    std::uniform_real_distribution<double> randomDistribution{ 0.1, 10 };
    for (int n = 0; n < 1000; ++n)
    {
        
        double num = randomDistribution(randomEngine);
        double root = BabylonianSqrt(num, 1e-10, 1.0);
        std::cout << "The root for " << num << " is " << root << '\n';
    }
}


