#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <cmath>
#include "Constants.h"
#include <limits>
#include "IntToBin.h"

int main()
{
	bool playingAgain = false;
	do {
		system("cls");
		greetMessage();
		int inputNumber = getInput();
		convertToBinary(inputNumber);
		playingAgain = isPlayingAgain();


	} while (playingAgain);
	return 0;
}

bool isPlayingAgain()
{
	using namespace std;
	string playAgain = "";
	cout << "Would you like to convert another Integer? (Y/N)" << endl;
	getline(cin, playAgain);
	return (playAgain[0] == 'y' || playAgain[0] == 'Y');
}



/* Convert int to bin */
void convertToBinary(int a)
{
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

void outputResult(int* outputArray, int numIterate)
{
	using namespace std;
	int i = numIterate;
	cout << "\n Binary Result: ";
	while (i > 0)
	{
		std::cout << outputArray[i];
		i--;
	}
	cout << endl;
}

/* Get the input and send to conversion*/
int getInput()
{
	using namespace std;
	int inputNumber;
	string inputString = "";
	cout << "Please enter an integer: ";
	getline(cin, inputString);
	stringstream convert(inputString);
	convert >> inputNumber;
	return inputNumber;

}

void greetMessage()
{
	std::cout << "Welcome, this program will convert a number to it's binary equivalent.(Max size of 16bits)\n\n";
}



