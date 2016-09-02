#define ExpoGen_h
#include "resource.h"

void greetMessage();
void runGenerator();
int getBaseNumber();
int getExponent();
void generateList(int base, int exp);

namespace expoConstants
{
	constexpr double exponent = 1.1;
}
