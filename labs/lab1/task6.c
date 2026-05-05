#include <stdio.h>

int main(void)
{
	FILE *input_file, *output_file;
	char input_filename[] = "task6-2.txt";
	char output_filename[] = "task6-output.txt";
	char buffer[100];

	input_file = fopen(input_filename, "r");
	if (input_file == NULL) {
		printf("Cannot open input file: %s\n", input_filename);
		return 1;
	}

	output_file = fopen(output_filename, "w");
	if (output_file == NULL) {
		printf("Cannot open output file: %s\n", output_filename);
		fclose(input_file);
		return 1;
	}

	for (int i = 0; i < 3; i++) {
		if (fgets(buffer, sizeof(buffer), input_file) != NULL) {
			fputs(buffer, output_file);
		} else {
			break;
		}
	}

	fclose(input_file);
	fclose(output_file);
	return 0;
}
