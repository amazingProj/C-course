#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef union Type_t
{
	char chr;
	size_t number;
	char *str;
	bool bl;
} Type;

typedef struct Item_t
{
	Type *type;
	int typecode;
} Item;

typedef struct Node_t
{
	Item *data;
	struct Node_t *Next;
} Node, *PNode;

typedef struct Stack_t
{
    //Linked list by pointers
	PNode list;
	PNode top;
} Stack, *PStack;

Stack *CreateStack();

void DeleteStack(Stack *stack);

void StackPush(Stack *stack, PNode item);

Node *StackPop(Stack *stack);

int StackGetLastError(Stack *stack);

size_t StackSize(Stack *stack);

void StackPrint(Stack *stack);

