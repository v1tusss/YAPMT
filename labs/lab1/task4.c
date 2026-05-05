#include <stdio.h>

int main(void)
{
	double a, b, c;

	printf("Enter a:\n");
	scanf("%lf", &a);

	printf("Enter b:\n");
	scanf("%lf", &b);

	printf("Enter c:\n");
	scanf("%lf", &c);

	if (a == 0) {
		if (b == c) {
			printf("Infinite number of solutions\n");
		} else {
			printf("No solution\n");
		}
		return 0;
	}

	printf("x=%.1lf\n", (c - b) / a);
	return 0;
}
