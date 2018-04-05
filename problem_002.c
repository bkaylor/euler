// Euler 2
// Even Fibonacci numbers
#include <stdio.h>

void main()
{
    int i, j, k, sum;
    i = 1;
    j = 2;
    sum = 2;
    k = i + j;

    while (k < 4000000)
    {
        if (k%2 == 0)
            sum += k;
        i = j;
        j = k;
        k = i + j;
    }

    printf("%i", sum);
}
