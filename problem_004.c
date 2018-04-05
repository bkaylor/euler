// Euler 4
// Largest palindrome, product of two 3 digit numbers
#include <stdio.h>
#include <stdlib.h>

int isPalindrome(int);

int main(void)
{
	int i, j;
	int save = -1;

	for (i = 100; i < 1000; ++i)
	{
		for (j = 100; j < 1000; ++j)
		{
			if (isPalindrome(i * j))
			{
				if (i * j > save)
					save = i * j;
			}
		}
	}

	printf("%d\n", save);
	return 0;
}

int isPalindrome(int x)
{
	// Count digits
	int digitc = 0;
	{
		int i = 1;
		while (x >= i)
		{
			++digitc;
			i *= 10;
		}
	}

	// Put each digit into an array as int
	int *digitarr = malloc(digitc * sizeof(int));
	{
		int i, j;
		for (i = 0, j = 10; i < digitc; ++i, j *= 10)
		{
			digitarr[i] = (x % j) / (j / 10); 
		}
	}

	// Reverse each digit, put into new array
	int *digitarr_rev = malloc(digitc * sizeof(int));
	{
		int i, j, temp;
		for (i = 0, j = digitc-1; i < (digitc/2)+1; ++i, --j)
		{
			digitarr_rev[i] = digitarr[j];
			digitarr_rev[j] = digitarr[i];	
		}
	}

	// Compare arrays
	int cmp = 1;
	{
		int i;
		for (i = 0; i < digitc; ++i)
		{
			if (digitarr[i] != digitarr_rev[i])
			{
				cmp = 0;
				break;
			}
		}
	}

	return cmp;
}
