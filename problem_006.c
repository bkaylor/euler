// Euler 6
// (1 + 2 + 3 ... + 100)^2 - (1^2 + 2^2 + 3^2 ... + 100^2)

#include <stdio.h>

int main(void)
{
	unsigned long squareOfSum = 0;
	int i;
	for (i = 1; i <= 100; ++i)
	{
		squareOfSum += i;	
	}

	squareOfSum *= squareOfSum;

	unsigned long sumOfSquare = 0;
	int j;
	for (j = 1; j <= 100; ++j)
	{
		sumOfSquare += j * j;
	}

	printf("%ld\n", squareOfSum - sumOfSquare);
	return 0;
}
