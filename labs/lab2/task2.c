#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	FILE *file = fopen("task2.txt", "w");
	int i,n;
	scanf("%d", &n);
	int mas[n];
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		mas[i] = rand() % 100;
		printf("%d ", mas[i]);
	}
	for (i = n-1; i >= 0; i--) {
		fprintf(file, "%d ", mas[i]);
	}
	fclose(file);
	return 0;
}

