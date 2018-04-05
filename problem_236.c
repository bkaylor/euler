#include <stdio.h>

//
// Per-product spoilage rate = number of products gone bad / number of products supplied for each
// Overall spoilage rate = total number of products gone bad / total number of products from that supplier
//
// m is ppsr of ppsr_a / ppsr_b for each product
// m is osr_a / osr_b
// There are 35 m where m > 1
// What is the largest one? 
//

int a[5] = {5248, 1312, 2624, 5760, 3936};
int b[5] = {640, 1888, 3776, 3776, 5664};

int main(int argc, char *argv[])
{
	int a_c, b_c;
	for (int i = 0; i < 5; ++i)
	{
		a_c += a[i];
		b_c += b[i];
	}
	return 0;
}
