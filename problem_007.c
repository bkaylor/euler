#include <stdio.h>
#include <math.h>

#define DESIRED_PRIME 10001 

int main(int argc, char **argv)
{
	long long i = 2;
	int j = 0;
	int prime = 1;
	long long num;
	while(j < DESIRED_PRIME)
	{
		prime = 1;
		for (long long k = 2; k <= floor(sqrt(i)); ++k)
		{
			if (i % k == 0)
			{
				prime = 0;
				break;
			}
		}

		if (prime)
		{
			++j;
			num = i;
		}
		++i;
	}
	printf("%lli\n", num);
}
