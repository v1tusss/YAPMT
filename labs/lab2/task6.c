#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

struct Stack {
	int data[STACK_SIZE];
	int top;
};

int isempty(struct Stack *stk)
{
	return stk->top == 0;
}

int isfull(struct Stack *stk)
{
	return stk->top == STACK_SIZE;
}

void push(struct Stack *stk, int k)
{
	if (!isfull(stk)) {
		stk->data[stk->top] = k;
		stk->top++;
	} else {
		printf("Stack is full\n");
	}
}

int pop(struct Stack *stk)
{
	if (!isempty(stk)) {
		stk->top--;
		return stk->data[stk->top];
	}

	printf("Stack is empty\n");
	return 0;
}

int TopElement(struct Stack *stk)
{
	if (!isempty(stk)) {
		return stk->data[stk->top - 1];
	}

	printf("Stack is empty\n");
	return 0;
}

void PrintStack(struct Stack *stk)
{
	for (int n = stk->top - 1; n >= 0; n--) {
		printf("%d\n", stk->data[n]);
	}
}

int main(void)
{
	struct Stack *stk = malloc(sizeof(struct Stack));
	if (stk == NULL) {
		printf("Memory allocation error\n");
		return 1;
	}
	stk->top = 0;

	int n = 5;
	int k;
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		push(stk, k);
	}

	printf("Top element: %d\n", TopElement(stk));
	printf("Popped element: %d\n", pop(stk));
	printf("Stack after pop:\n");
	PrintStack(stk);

	free(stk);
	return 0;
}
