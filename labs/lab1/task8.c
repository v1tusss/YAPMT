#include <stdio.h>

int main(void)
{
	FILE *file = fopen("task8-1.txt", "r");
	if (file == NULL) {
		printf("Cannot open file task8-1.txt\n");
		return 1;
	}

	char info[100];
	printf("Enter information: ");
	fgets(info, sizeof(info), stdin);

	FILE *temp = fopen("temp.txt", "w");
	if (temp == NULL) {
		printf("Cannot create temporary file\n");
		fclose(file);
		return 1;
	}

	fputs(info, temp);

	int c;
	while ((c = fgetc(file)) != EOF) {
		fputc(c, temp);
	}

	fclose(file);
	fclose(temp);

	remove("task8-1.txt");
	rename("temp.txt", "task8-1.txt");
	return 0;
}
