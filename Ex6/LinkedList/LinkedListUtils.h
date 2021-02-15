#pragma once
#include<stdio.h>
#include<limits.h>

/// <summary>
/// value of any type
/// </summary>
typedef int T;

/// <summary>
/// Open to user decision 
/// </summary>
typedef int ListDataType;

typedef union Type_t
{
	int integer;
} Type;

/**
 *
 * @attention T value is void * that can be pointed to any type
 *
 */
typedef struct Node_t
{
	struct Node_t* next;
	struct Node_t* prev;
	T value;
} Node, * PNode;

/**
 *
 * @attention T value is void * that can be pointed to any type
 *
 */
typedef struct List_t
{
	PNode root;
	ListDataType dataType;
	size_t sizeOfList;
} List;

void DeleteNode(PNode);

PNode GetNodeInIndex(List* list, size_t index);

void InitRoot(List* list, T value);