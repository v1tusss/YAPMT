#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int i, n;
	scanf("%d", &n);
	int mas[n];
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		mas[i] = rand() % 100;
		printf("%d ", mas[i]);
	}
	return 0;
}
