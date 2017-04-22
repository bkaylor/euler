// Euler 3
// Largest prime factor

#include <stdio.h>
#include <math.h>

int main(void)
{
	long long num;
	num = 600851475143;

	long long i;
	for (i = 2; i < floor(sqrt(num)); ++i)
	{
		if (num % i == 0)
		{
			printf("\n%d\n", i);
			num /= i;
			i = 2;
		}
	}
	printf("\n%lld\n", num);
	return 0;
}
