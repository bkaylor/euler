// Euler 1
// Multiples of 3 and 5
#include <stdio.h>

int main(int argc, char **argv)
{
    int n;
    if (argc > 1)
        sscanf(argv[1], "%i", &n);
    else
        printf("Usage: a.out <integer>\n");

    int i, sum;
    sum = 0;
    for (i = 3; i < n; ++i)
    {
        if (i%3 == 0 || i%5 == 0)
        {
            sum += i;
        }
    }
    printf("%i\n", sum);
    return;
}
