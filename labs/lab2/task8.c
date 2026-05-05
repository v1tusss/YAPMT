#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int Operator(char oper)
{
	return oper == '+' || oper == '-' || oper == '*' || oper == '/';
}

int Priority(char oper)
{
	if (oper == '*' || oper == '/') {
		return 2;
	}
	if (oper == '+' || oper == '-') {
		return 1;
	}
	return 0;
}

void InfixToPostfix(char infix[], char postfix[])
{
	struct Stack *stk = malloc(sizeof(struct Stack));
	if (stk == NULL) {
		printf("Memory allocation error\n");
		postfix[0] = '\0';
		return;
	}
	stk->top = -1;

	int i = 0;
	int j = 0;
	push(stk, '(');
	strcat(infix, ")");

	char symbol = infix[i];
	while (symbol != '\0') {
		if (symbol == '(') {
			push(stk, symbol);
		} else if ((symbol >= '0' && symbol <= '9') || symbol == '.') {
			postfix[j++] = symbol;
		} else if (Operator(symbol)) {
			int item = pop(stk);
			while (Operator(item) && Priority(item) >= Priority(symbol)) {
				postfix[j++] = item;
				item = pop(stk);
			}
			push(stk, item);
			push(stk, symbol);
		} else if (symbol == ')') {
			int item = pop(stk);
			while (item != '(') {
				postfix[j++] = item;
				item = pop(stk);
			}
		}
		i++;
		symbol = infix[i];
	}

	postfix[j] = '\0';
	free(stk);
}

int main(void)
{
	char infix[100];
	char postfix[100];

	fgets(infix, sizeof(infix) - 2, stdin);
	infix[strcspn(infix, "\n")] = '\0';
	InfixToPostfix(infix, postfix);
	printf("%s\n", postfix);
	return 0;
}
