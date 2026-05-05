#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

struct Stack {
	int data[STACK_SIZE];
	int top;
};

int isempty(struct Stack *stk)
{
	return stk->top == -1;
}

int isfull(struct Stack *stk)
{
	return stk->top == STACK_SIZE - 1;
}

void push(struct Stack *stk, int k)
{
	if (!isfull(stk)) {
		stk->top++;
		stk->data[stk->top] = k;
	} else {
		printf("Stack is full\n");
	}
}

int pop(struct Stack *stk)
{
	if (!isempty(stk)) {
		int k = stk->data[stk->top];
		stk->top--;
		return k;
	}

	printf("Stack is empty\n");
	return 0;
}

int main(void)
{
	struct Stack *stk = malloc(sizeof(struct Stack));
	if (stk == NULL) {
		printf("Memory allocation error\n");
		return 1;
	}
	stk->top = -1;

	FILE *file = fopen("task7.txt", "r");
	if (file == NULL) {
		printf("Cannot open input file task7.txt\n");
		free(stk);
		return 1;
	}

	int c;
	while ((c = fgetc(file)) != EOF) {
		if (c >= '0' && c <= '9') {
			push(stk, c - '0');
		} else if (c == '+' || c == '-' || c == '*' || c == '/') {
			int b = pop(stk);
			int a = pop(stk);
			int res = 0;

			switch (c) {
			case '+':
				res = a + b;
				break;
			case '-':
				res = a - b;
				break;
			case '*':
				res = a * b;
				break;
			case '/':
				res = a / b;
				break;
			}
			push(stk, res);
		}
	}

	printf("%d\n", pop(stk));
	fclose(file);
	free(stk);
	return 0;
}
