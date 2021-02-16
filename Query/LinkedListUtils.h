#pragma once
#include<stdio.h>
#include<limits.h>

/// <summary>
/// Open to user decision 
/// </summary>
typedef int ListDataType;

/**
* struct of node 
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
  * struct of list 
  * @attention T value is void * that can be pointed to any type
  *
  */
typedef struct List_t
{
	PNode root;
	size_t sizeOfList;
} List;

/**
  * deletes node 
  * @param  node - a node
  * @warning cannot deletes NULL
  *
  */
void DeleteNode(PNode);

/**
  * gets node in index 
  * @param  list - a list
  * @param  index - a place of node
  * @return pointer to a node
  * @attention when index is bigger that size of list retuns NULL
  *
  */
PNode GetNodeInIndex(List* list, size_t index);

/**
  * gets node in index
  * @param  list - a list
  * @param  neValue - a new value
  * @return pointer to a node
  * @attention if list is NULL returns NULL.
  *
  */
PNode InitRoot(List* list, ListDataType newValue);
