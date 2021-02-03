#include "Stack.h"

Stack * CreateStack()
{
	Stack *stack;
	/*stack.list = malloc(sizeof(Node));
	stack.list->data = malloc(sizeof(Item));
	stack.list->Next = malloc(sizeof(Node));
	stack.root = malloc(sizeof(Node));
	stack.root = NULL;
	stack.list->data = NULL;
	stack.list->Next = NULL;
	stack.list = NULL;*/

	stack = malloc(sizeof(Stack));
	stack->list = malloc(sizeof(Node));
	stack->list->data = malloc(sizeof(Item));
	stack->list->Next = malloc(sizeof(Node));
	stack->top = malloc(sizeof(Node));
	stack->top = NULL;
	/*
	stack->list->data = NULL;
	stack->list->Next = NULL;
	stack->list = NULL;
	*/
	Stack *stk = stack;
	return stack;
}

void DeleteStack(Stack *stack)
{
	while (!StackGetLastError(stack))
	{
		PNode pNode = StackPop(stack);

		// free a string, if it is.
		if (pNode->data->typecode == 3)
		{
			free(pNode->data->type);
		}
		free(pNode->Next);
		free(pNode->data);
	}
	free(stack);
}

void StackPush(Stack * stack, PNode item)
{
	if (StackGetLastError(stack))
	{
		CreateStack(stack);
	}
	else
	{
		PNode oldTop = malloc(sizeof(Node));
		oldTop = stack->list;
		PNode p = oldTop->Next;
		Item *item = p->data;
		while (oldTop->Next != NULL)
		{
			oldTop = oldTop->Next;
		}
		oldTop->Next = item;
	}

	stack->top = item;
}

Node * StackPop(Stack * stack)
{
	if (StackGetLastError(stack))
	{
		return NULL;
	}
	else 
	{
		PNode current = stack->list;
		while (current != NULL
			&& current->Next != stack->top)
		{
			current = current->Next;
		}

		stack->top = current;
		current->Next = NULL;
	}

	return stack->top;
}

int StackGetLastError(Stack * stack)
{
	return (stack->list == NULL);
}

size_t StackSize(Stack * stack)
{
	int count = 0;
	PNode current = stack->list;

	while (current != NULL)
	{
		current = current->Next;
		count++;
	}

	return count;
}

void StackPrint(Stack * stack)
{
	PNode current = stack->list;

	while (current != NULL)
	{
		switch (current->data->typecode)
		{
		case 1:
			printf("%10 %c \n", current->data->type->chr);
			break;

		case 2:
			printf("%10 %d \n", current->data->type->number);
			break;

		case 3:
			printf("%10 %s \n", current->data->type->str);
			break;

		case 4:
			(current->data->type->bl) ? printf("%s", "TRUE") : printf("%s", "False");
			printf("%10c \n", current->data->type);
			break;

		default:
			break;

		}
		current = current->Next;
	}
}
