// Euler 3
// Largest prime factor
// NOTE: This works, but is extremely bad. p3alt.c is lightyears better.
#include <stdio.h>
#include <math.h>

// Slow prime test
int isPrime(long long totest)
{
	long long i;
	if (totest % 2 == 0)
		return 0;

	for (i = 3; i < totest; i+=2)
	{
		if (totest % i == 0)
			return 0;
	}
	return 1;
}

// Return largest prime factor less than sqrt
long long find_lpf (long long target)
{    
	long long lpf;
    long long save;

    for (lpf = 2; lpf <= floor(sqrt(target)); ++lpf)
    {
		printf("\r%.2f%%", 100 * ((double)lpf / floor(sqrt(target))));
        if (isPrime(lpf) && target % lpf == 0)
        {
            save = lpf;
        }
    }
	return save;
}

int main(void)
{
    // That's 600 billion... etc
	long long start;
    long long target;
    long long save;
	long long product;

	start = 600851475143;
	product = 1;
	target = start;

	while (!isPrime(target))
	{
		save = find_lpf(target);
		product *= save;
		printf("\n%lld\n", save);
		target = target / save;
	} 

	printf("\n%lld\n", start/product);

	return 0;
}
