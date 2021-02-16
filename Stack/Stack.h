#pragma once
#include "LinkedList.h"

/**
  * class represents stack
  */
typedef struct Stack_t
{
	PNode top;
	List *list;
} Stack;

/**
  * creates a stack 
  * @return a new stack
  * @see function: CreateList()
  *
  */
Stack *CreateStack();

/**
  * deletes a stack 
  * @param  stack - a stack
  * @attention function is closed to stack is null 
  *
  */
void DeleteStack(Stack *stack);

/**
  * push a new node to a stack 
  * @param  stack - a stack
  * @param  item - an node item 
  * @see function: PushFront()
  * 
  */
void StackPush(Stack *stack, PNode item);

/**
  * pop the top of the stack
  * @param  stack - a stack
  * @return the poped node
  * @see PopFront()
  * @warning the same as PopFront function
  *
  */
Node *StackPop(Stack *stack);

/**
  * if stack is empty
  * @param  stack - a stack
  * @return 1 if stack is empty, 0 if it is not
  *
  */
int StackGetLastError(Stack *stack);

/**
  * get the size of stack
  * @param stack - a stack
  * @return the size of the stack
  * @see GetListSize()
  * @warning the same as the function below
  *
  */
size_t StackSize(Stack *stack);

/**
  * prints a stack
  * @param stack - a stack
  *
  */
void StackPrint(Stack *stack);

