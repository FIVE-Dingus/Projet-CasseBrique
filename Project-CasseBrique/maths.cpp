#include "maths.h"
#include <Math.h>

bool Maths::isBeetwen(int toCheck, int extrema1, int extrema2)
{
	return abs(extrema1 - toCheck) + abs(toCheck - extrema2) == abs(extrema1 - extrema2);
}