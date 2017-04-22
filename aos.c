#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct item_struct 
{
	char *data;
	int size;
};

int main(int argc, char *argv[])
{
	srand(time(NULL));

	struct item_struct *DataArray = malloc(sizeof(struct item_struct) * 1000000);

	int i;
	for (i = 0; i < 1000000; ++i)
	{
		DataArray[i].size = rand() % 100;
		DataArray[i].data = malloc(sizeof(char) * DataArray[i].size);

		int j;
		for (j = 0; j < (DataArray[i].size - 1); ++j)
		{
			DataArray[i].data[j] = 65 + (rand() % 26); 
		}
		DataArray[i].data[j] = '\0';
	}

	printf("Data written.\n");
	int k;
	for (k = 0; k < 20; ++k)
	{
		printf("Sleeping... %i\r", k);
		sleep(1);
	}

	FILE *file;
	file = fopen("data.txt", "w");
	for (i = 0; i < 1000000; ++i)
	{
		fprintf(file, "%s\n", DataArray[i].data);
	}
	fclose(file);

	return 0;
}
