#include "Stack.h"

int main()
{
	int i = 0;
	int count = 0;

	Stack *stack;
	stack = CreateStack();
	PNode node = malloc(sizeof(Node));
	node->data = malloc(sizeof(Item));
	node->data->type = malloc(sizeof(Type));
	node->data->type->number = 333;
	node->data->typecode = 2;
	StackPush(stack, node);
	StackPush(stack, node);
	StackPush(stack, node);
	node->data->type->chr = 'l';
	node->data->typecode = 1;
	StackPush(stack, node);

	StackPrint(stack);

	return 0;
}
