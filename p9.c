#include <stdio.h>

// 
// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
// a^2 + b^2 = c^2
// 
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
// 
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.
// 

typedef struct PythagTrip_struct {
	int a;
	int b;
	int c;
} PythagTrip;

int main(int argc, char *argv[])
{
	int h = 1000;
	PythagTrip triplet;

	int i,j,k;
	for (i = 1; i < 1000; ++i)
	{
		for (j = 1; j < 1000; ++j)
		{
			k = 1000-i-j;
			if (k != 0 && i*i + j*j == k*k)
			{
				triplet.a = i;
				triplet.b = j;
				triplet.c = k;
			}
		}
	}

	printf("%i %i %i -> %d\n", triplet.a, triplet.b, triplet.c, triplet.a*triplet.b*triplet.c);
	return 0;
}
