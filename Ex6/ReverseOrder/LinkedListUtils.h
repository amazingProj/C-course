#pragma once
#include<stdio.h>
#include<limits.h>

/// <summary>
/// Open to user decision 
/// </summary>
typedef int ListDataType;

/**
*
* @attention T value is void * that can be pointed to any type
*
*/
typedef struct Node_t
{
	struct Node_t* next;
	struct Node_t* prev;
	ListDataType value;
} Node, *PNode;

/**
*
* @attention T value is void * that can be pointed to any type
*
*/
typedef struct List_t
{
	PNode root;
	size_t sizeOfList;
} List;

void DeleteNode(PNode);

PNode GetNodeInIndex(List* list, size_t index);

PNode InitRoot(List* list, ListDataType value);
