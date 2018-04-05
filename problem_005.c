// Euler 5
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <stdio.h>

int main(void)
{
	int i = 20;
	while (1)
	{
		int j;
		int div = 1;
		for (j = 1; j <= 20; ++j)
		{
			if (i % j != 0)
			{
				div = 0;
				continue;
			}
		}
		if (div)
			break;
		++i;
	}

	printf("%d\n", i);
	return 0;
}
