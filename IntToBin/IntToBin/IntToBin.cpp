#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <cmath>
#include "Constants.h"
#include <limits>

void outputResult(int* outputArray, int numIterate)
{
	int i = numIterate;
	std::cout << "\n Binary Result: ";
	while (i > 0)
	{
		std::cout << outputArray[i];
		i--;
	}
	std::cout << "\n\n";
	std::cout << "Press Enter to try again.";
	std::cin.ignore(32767, '\n');
}

/* Determine how many places the binary number will span*/
int getBinLength(int i)
{
	int m = 1;
	int c = 0;
	while (i > m)
	{
		m *= 2;
		c++;
	}
	return c;
}



/* Convert int to bin */
void convertToBinary(int a)
{
	if (a <= 0)
	{
		throw 2;
	}
	int i = 1;
	int binBit;
	double curMult;

	int binOutput[myConstants::MAX_ARRAY_SIZE];


	int maxExponent = getBinLength(a);

	int binLength = getBinLength(a) + 1;

	int origBinLength = binLength;
	if (maxExponent > myConstants::MAX_ARRAY_SIZE)
	{
		throw "\n\n The Integer you entered exeeds 16bits in Binary Form. Please enter a lower number";
	}
	curMult = pow(2, maxExponent);
	while (maxExponent >= 0)
	{
		if (a >= curMult)
		{
			binBit = 1;
			a -= static_cast<int> (curMult);
		}
		else
		{
			binBit = 0;
		}
		binOutput[binLength] = binBit;
		binLength--;
		maxExponent--;
		curMult /= 2;

	}

	outputResult(binOutput, origBinLength);
}
/* Get the input and send to conversion*/
void getInput()
{
	using namespace std;
	cout << "Please enter an integer or type 0 to exit: ";
	int inputNumber;
	while (!(cin >> inputNumber)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	cin >> inputNumber;
	if (cin.fail())
	{
		throw "Please enter an Integer";
	}
	convertToBinary(inputNumber);

}

void greetMessage()
{
	std::cout << "Welcome, this program will convert a number to it's binary equivalent.(Max size of 16bits)\n\n";
}

void startLoop()
{
	system("cls");
	greetMessage();
	getInput();
	std::cin.ignore(32767, '\n');
}

int main()
{
	int zz = 1;
	while (zz = 1)
	{
		startLoop();
		/*catch (const char* strException) {
		std::cerr << "Error: " << strException;
		std::cin.ignore(32767, '\n');
		std::cin.clear();
		Sleep(2500);
		}
		catch (int e) {
		exit(0);*/

	}
	std::cin.ignore(32767, '\n');
	return 0;
}

