#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Usage: %s <array_size>\n", argv[0]);
		return 1;
	}

	int n = atoi(argv[1]);
	if (n <= 0) {
		printf("Array size must be positive\n");
		return 1;
	}

	float mas[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		mas[i] = (float)rand() / RAND_MAX;
		printf("%.2f ", mas[i]);
	}
	printf("\n");
	return 0;
}
