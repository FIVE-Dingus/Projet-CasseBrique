#include "maths.h"

bool Maths::isBeetwen(int toCheck, int extrema1, int extrema2)
{
	if (extrema1 > extrema2)
	{
		int temp = extrema2;
		extrema2 = extrema1;
		extrema1 = temp;
	}

	return (extrema1 <= toCheck && toCheck <= extrema2);
}