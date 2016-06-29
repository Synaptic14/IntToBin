#include "stdafx.h"
#include <iostream>
#include <string>
#include "ExpoGen.h"

int main()
{
	greetMessage();
	runGenerator();
}

void greetMessage()
{
	using namespace std;
	cout << "Welcome to the Exponential Number Generator" << endl;
}

int runGenerator()
{
	int baseNumber = getBaseNumber();
	double exponent = getExponent();
	int numLimit = getNumLimit();
	generateList(baseNumber, exponent, numLimit);
}

int getBaseNumber()
{
	using namespace std;
	int baseNumber = 0;
	cout << "Please enter a whole number as the Base Number: ";
	cin >> baseNumber;
	return baseNumber;
}

double getExponent()
{
	using namespace std;
	double exponent = 0;
	cout << "Please enter the exponent: ";
	cin >> exponent;
	return exponent;
}

int getNumLimit()
{
	using namespace std;
	int numLimit = 0;
	cout << "Please enter the Number Limit: ";
	cin >> numLimit;
	return numLimit;
}

int generateList(int base, double exp, int numLimit)
{
	while (int i < numLimit)
	{
		int nextNumber = (base * exp) + base;
	}
	
}