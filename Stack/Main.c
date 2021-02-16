#include "Stack.h"

void PrintTestResult(size_t x, int code)
{
	if (code == 1)
	{
		printf("%13d %10s\n", x, "Succeded");
	}
	else
	{
		printf("%13d %10s\n", x, "Failed");
	}

}
int main(void)
{
	printf("%13s %10s \n", "Test number", "Result");

	Stack *stack = CreateStack();

	PNode node = (PNode)(malloc(sizeof(Node)));
	int x = 190;
	node->value = x;
	StackPush(stack, node);

	x = 1908;
	node->value = x;
	StackPush(stack, node);

	x = 19023;
	node->value = x;
	StackPush(stack, node);

	x = 12;
	node->value = x;
	StackPush(stack, node);

	x = 121;
	node->value = x;
	StackPush(stack, node);

	x = 8;
	node->value = x;
	StackPush(stack, node);

	StackPrint(stack);

	PrintTestResult(1, 1);
	
	DeleteStack(stack);
	
	PrintTestResult(2, 1);
	
	return 0;
}