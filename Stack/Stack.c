#include "Stack.h"

/**
  * @file Stack.h
  */
Stack *CreateStack()
{
	Stack *stack = (Stack *)(malloc(sizeof(Stack)));
	stack->list = CreateList();
	if (stack->list == NULL)
	{
		return NULL;
	}

	stack->top = stack->list->root;

	return stack;
}

void DeleteStack(Stack *stack)
{
	if (stack == NULL)
	{
		return;
	}

	FreeList(stack->list);
	DeleteNode(stack->top);
	free(stack);
}

void StackPush(Stack *stack, PNode item)
{
	if (stack == NULL)
	{
		return NULL;
	}

	PushFront(stack->list, item->value);
}

Node *StackPop(Stack *stack)
{
	if (stack == NULL)
	{
		return NULL;
	}

	return PopFront(stack->list);
}

int StackGetLastError(Stack *stack)
{
	return (stack->list == NULL);
}

size_t StackSize(Stack *stack)
{
	if (stack == NULL)
	{
		return -1;
	}

	return GetListSize(stack->list);
}

void StackPrint(Stack *stack)
{
	if (stack == NULL)
	{
		return;
	}

	printf("%13s  %10s \n", "Serial number", "Value");
	PNode iterator = stack->list->root;
	for (size_t i = 0; i < stack->list->sizeOfList; ++i)
	{
		if (iterator->value == NULL)
		{
			continue;
		}
		printf("%13d  %10d \n", i, iterator->value);
		iterator = iterator->next;
	}
}