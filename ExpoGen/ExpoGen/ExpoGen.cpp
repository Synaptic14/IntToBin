#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include "ExpoGen.h"

int main()
{
	greetMessage();
	runGenerator();
	return 0;
}

void greetMessage()
{
	using namespace std;
	cout << "Welcome to the Exponential Number Generator" << endl;
}

void runGenerator()
{
	int baseNumber = getBaseNumber();
	int exponent = getExponent();
	generateList(baseNumber, exponent);
}

int getBaseNumber()
{
	using namespace std;
	int baseNumber = 0;
	cout << "Please enter a whole number as the Base Number: ";
	cin >> baseNumber;
	return baseNumber;
}

int getExponent()
{
	using namespace std;
	double exponent = 0;
	cout << "Please enter the exponent: ";
	cin >> exponent;
	static_cast<int> (exponent);
	return exponent;
}

void generateList(int base, int exp)
{
	int i = 1;
	while (i < exp)
	{
		int currentNumber = std::pow(base, i);
		std::cout << i + "." << currentNumber << std::endl;
		i++;
	}
}
