#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int size = 2;
	char *data;
	data = malloc(size);

	int i;
	for (i = 0; i < 32; ++i)
	{
		free(data);

		size = size * 2;
		data = malloc(size);

		printf("Allocated %i bytes\r", size);
		sleep(2);
	}

	return 0;
}
