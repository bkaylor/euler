#include <stdio.h>
#include <math.h>

// Euler 39
/*
 *	If p is the perimeter of a right angle triangle with 
 *	integral length sides, {a,b,c}, there are exactly three solutions for p = 120.
 *	{20,48,52}, {24,45,51}, {30,40,50}
 *	For which value of p <= 1000 is the number of solutions maximised?
 */

/*
 * p = a + b + c
 * c = sqrt(a*a + b*b)
*/

int main(int argc, char *argv[])
{
	// Init
	int lim;
	int p;
	int i, j, k;
	int temp;

	// Upper perimeter bound
	if (argc == 2)
		lim = atoi(argv[1]);
	else lim = 1000;

	int sols[lim+1];

	// Init array
	for (temp = 0; temp < lim+1; ++temp) sols[temp] = 0;


	// For each perimeter up to lim
	for (p = 3; p <= lim; ++p)
	{
		printf("\r%d    ", p);

		// For each value of one side
		for (i = 1; i < p-1; ++i)
		{
			// The other side can go up to p - i - 1
			for (j = 1; j < (p - i); ++j)
			{
				// Fill in last side
				k = p - i - j;
				
				// If the triangle is a right triangle 
				if (sqrt((double) i*i + j*j) == (double) k)
				{
					// Solution has been found
					++sols[p];
				}
			}
		}
	}

	printf("\r");

	// Find perimeter with most solutions
	int x, largest;
	largest = 0;
	for (x = 0; x < lim+1; ++x)
	{
		if (sols[x] > largest)
			largest = sols[x];	
	}

	// Print those perimeters
	for (x = 0; x < lim+1; ++x) if (sols[x] == largest) printf("p = %d: %d solutions\n", x, largest);

	return 0;
}
