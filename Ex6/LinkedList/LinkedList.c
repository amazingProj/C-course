#include "LinkedList.h"
#include<stdbool.h>
/**
  * @file LinkedList.h
  */
/// <summary>
/// Global variable for number of existed lists
/// </summary>
size_t numberOfLists = 0;

List* CreateList()
{
	List *list = (List *)(malloc(sizeof(List)));
	if (list == NULL)
	{
		printf("%s", "memory allocation error\n");
		return NULL;
	}
	list->root = (PNode)(malloc(sizeof(Node)));
	list->root->next = (PNode)(malloc(sizeof(Node)));
	list->root->prev = (PNode)(malloc(sizeof(Node)));
	list->root->prev = NULL;
	list->root->next = NULL;
	list->sizeOfList = 0;
	++numberOfLists;
	return list;
}

void FreeList(List *list)
{
	if (list == NULL)
	{
		return;
	}
	while (list->root->next != NULL)
	{
		free(list->root->value);
		free(list->root->prev);
		list->root = list->root->next;
		free(list->root->next);
	}
	free(list->root);
	free(list->sizeOfList);
	--numberOfLists;
}

size_t GetListSize(List *list)
{
	// calculate even though there is an variable in list.
	if (list == NULL)
	{
		//error occured with list
		return -1;
	}

	PNode iterator = list->root;
	size_t counter = 1;
	while (iterator->next != NULL)
	{
		iterator = iterator->next;
		++counter;
	}
	return counter;
}

Node *GetListHead(List *list)
{
	return list->root;
}


Node* Insert(List* list, ListDataType value, size_t index)
{
	if (list == NULL)
	{
		return NULL;
	}
	

	//for insert first time due to creating uninitialized node
	//when creating the list
	if (list->sizeOfList == 0)
	{
		++(list->sizeOfList);
		return InitRoot(list, value);
	}

	
	PNode newNode = (PNode)(malloc(sizeof(Node)));
	newNode->next = (PNode)(malloc(sizeof(Node)));
	newNode->prev = (PNode)(malloc(sizeof(Node)));

	if (index == 1)
	{
		newNode->value = value;

		newNode->next = list->root;
		newNode->next->prev = newNode;
		newNode->prev = NULL;

		list->root = newNode;
		++(list->sizeOfList);
		return newNode;
	}

	PNode iterator;

	if ((list->sizeOfList + 1) == index)
	{
		newNode->value = value;

		// itertor will be the end
		iterator = GetNodeInIndex(list, list->sizeOfList);
	
		iterator->next = newNode;

		newNode->prev = iterator;
		newNode->next = NULL;

		++(list->sizeOfList);
		return newNode;
	}

	if (list->sizeOfList == index)
	{
		iterator = GetNodeInIndex(list, list->sizeOfList);
		newNode->value = value;

		iterator->prev->next = newNode;

		newNode->prev = iterator->prev;
		newNode->next = iterator;

		iterator->prev = newNode;
		++(list->sizeOfList);
		return newNode;
	}

	newNode->value = value;
	 
	// get the node in place.
	iterator = GetNodeInIndex(list, index);
	
	if (iterator == NULL)
	{
		return NULL;
	}
	iterator->next->prev = newNode;
	
	newNode->next = iterator->next;

	iterator->next = newNode;
	newNode->prev = iterator;

	++(list->sizeOfList);
	return newNode;
}

Node* PushFront(List* list, ListDataType value)
{
	if (list == NULL)
	{
		return NULL;
	}
	return Insert(list, value, 1);
}

Node* PushBack(List* list, ListDataType value)
{
	if (list == NULL)
	{
		return NULL;
	}
	return Insert(list, value, GetListSize(list) + 1);
}

Node * PopFront(List* list)
{
	if (list == NULL)
	{
		return NULL;
	}

	PNode save = list->root;

	list->root = list->root->next;
	list->root->prev = NULL;
	
	--(list->sizeOfList);
	return save;
}

Node* PopBack(List* list)
{
	if (list == NULL)
	{
		return NULL;
	}

	PNode iterator = list->root;
	while (iterator->next != NULL)
	{
		iterator = iterator->next;
	}

	PNode save = iterator;

	iterator->prev->next = NULL;
	--(list->sizeOfList);
	return save;
}

void DeleteNodeFromList(List* list, size_t index)
{
	if (list == NULL)
	{
		return NULL;
	}

	if (index == 1)//root is deleted
	{
		list->root = list->root->next;
		list->root->prev = NULL;

		DeleteNode(list->root->prev);
	}
	PNode iterator;

	if (index == list->sizeOfList)
	{
		iterator = GetNodeInIndex(list, list->sizeOfList);
		iterator->prev->next = NULL;
		
		DeleteNode(iterator);
	}

	iterator = GetNodeInIndex(list, index);

	// when index is bigger than list->sizeOfList
	if (iterator == NULL)
	{
		return NULL;
	}

	iterator->prev->next = iterator->next;
	iterator->next->prev = iterator->prev;

	DeleteNode(iterator);
	--(list->sizeOfList);
}

Node* DeleteValue(List* list, size_t index)
{
	if (list == NULL)
	{
		return NULL;
	}

	PNode iterator = GetNodeInIndex(list, index);

	if (iterator == NULL)
	{
		return NULL;
	}

	iterator->value = NULL;
	--(list->sizeOfList);
	return iterator;
}

Node* Find(List* list, ListDataType value)
{
	if (list == NULL)
	{
		return NULL;
	}

	PNode iterator = list->root;
	for (size_t i = 0; i < list->sizeOfList; ++i)
	{
		if (iterator->value != NULL)
		{
			if (iterator->value == value)
			{
				return iterator;
			}
		}
		
		iterator = iterator->next;
	}
	
	printf("%s", "Error: value match did not found");
	return NULL;
}