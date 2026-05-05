#include <stdio.h>

int main(void)
{
	FILE *file = fopen("task7-1.txt", "a");
	if (file == NULL) {
		printf("Cannot open file task7-1.txt\n");
		return 1;
	}

	fprintf(file, "%s\n", "Hello, World!");
	fclose(file);
	return 0;
}
