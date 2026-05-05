#include <stdio.h>
#include <stdlib.h>

struct Product {
	char name[100];
	int price;
};

void ProductSort(struct Product prod[], int k)
{
	for (int i = 0; i < k - 1; i++) {
		for (int j = k - 1; j > i; j--) {
			if (prod[j - 1].price > prod[j].price) {
				struct Product t = prod[j - 1];
				prod[j - 1] = prod[j];
				prod[j] = t;
			}
		}
	}
}

int main(void)
{
	FILE *input_file = fopen("task5.txt", "r");
	if (input_file == NULL) {
		printf("Cannot open input file task5.txt\n");
		return 1;
	}

	FILE *output_file = fopen("task5_output", "w");
	if (output_file == NULL) {
		printf("Cannot open output file task5_output\n");
		fclose(input_file);
		return 1;
	}

	struct Product prod[100];
	int cnt = 0;

	while (cnt < 100 && fscanf(input_file, "%99s %d", prod[cnt].name, &prod[cnt].price) == 2) {
		cnt++;
	}

	ProductSort(prod, cnt);

	for (int i = 0; i < cnt; i++) {
		fprintf(output_file, "%s %d\n", prod[i].name, prod[i].price);
	}

	fclose(input_file);
	fclose(output_file);
	return 0;
}
