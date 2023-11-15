#include "maths.h"
#include <Math.h>

bool Maths::isBeetwen(int toCheck, int extrema1, int extrema2)
{
	return abs(extrema1 - toCheck) + abs(toCheck - extrema2) == abs(extrema1 - extrema2);
}

float Maths::min(float val1, float val2)
{
	return val1 > val2 ? val2 : val1;
}

float Maths::max(float val1, float val2)
{
	return val2 > val1 ? val2 : val1;
}