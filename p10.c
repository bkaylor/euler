#include <stdlib.h>
#include <stdio.h>

//
// Find the sum of all the primes below two million.
//

#define SIZE_LIM 2000000
#define PRIMES_UP_TO 2000000

int main(int argc, char *argv[])
{
	unsigned long long i;
	unsigned long long primes[SIZE_LIM];
	unsigned long long primec = 0;
	int primeq;
	unsigned long long sum = 0;


	// Get all primes under a number
	for (i = 2; i < PRIMES_UP_TO; ++i)
	{
		primeq = 1;
		unsigned long long j = 0;
		while (j < primec)
		{
			if (i % primes[j++] == 0)
			{
				primeq = 0;
				break;
			}
		}

		if (primeq)
		{
			primes[j] = i;
			++primec;
			sum += i;
		}
	}

	// What's wrong with this line?
	// printf("There are %d primes under %d\n", primec, PRIMES_UP_TO);
	printf("Sum -> %llu\n", sum);

	return 0;
}
