#include "LinkedList.h"
#include<stdbool.h>

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
	list->sizeOfList = 1;
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
	/*if (list->sizeOfList != NULL)
	{
		return list->sizeOfList;
	}*/
	PNode iterator = list->root;
	size_t counter = 0;
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
	List* newList = list;
	if (list == NULL)
	{
		newList = CreateList();
	}
	if (newList == NULL)
	{
		return NULL;
	}

	PNode iterator = GetNodeInIndex(newList, index);

	if (iterator == NULL)
	{
		return NULL;
	}

	//for insert first time due to creating uninitialized node
	//when creating the list
	if (index == 0 && list->root->value == NULL)
	{
		return InitRoot(list, value);
	}

	PNode newNode = (PNode)(malloc(sizeof(Node)));
	newNode->value = value;
	newNode->prev = iterator;
	newNode->prev->value = iterator->value;

	newNode->next = (PNode)(malloc(sizeof(Node)));
	if (iterator->next != NULL)
	{
		newNode->next = iterator->next;
	}
	else
	{
		newNode->next = NULL;
	}

	iterator->next = newNode;
	++(list->sizeOfList);
	return newNode;
}

Node* PushFront(List* list, ListDataType newValue)
{
	List *newList = list;
	if (list == NULL)
	{
		newList = CreateList();
	}
	if (newList == NULL)
	{
		return NULL;
	}
	return Insert(list, newValue, 0);
}

Node* PushBack(List* list, ListDataType newValue)
{
	List *newList = list;
	if (list == NULL)
	{
		newList = CreateList();
	}
	if (newList == NULL)
	{
		return NULL;
	}
	return Insert(list, newValue, GetListSize(list));
}

Node * PopFront(List* list)
{
	if (list == NULL)
	{
		return NULL;
	}
	list->root = list->root->next;
	list->root->value = list->root->next->value;
	--(list->sizeOfList);
	return list->root->prev;
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
	iterator->prev->next = NULL;
	return iterator;
}

void DeleteNodeFromList(List* list, size_t index)
{
	if (list == NULL)
	{
		return NULL;
	}
	PNode iterator = GetNodeInIndex(list, index);
	iterator->prev->next = iterator->next;
	iterator->next->prev = iterator->prev;
	DeleteNode(iterator);
}

Node* DeleteValue(List* list, size_t index)
{
	if (list == NULL)
	{
		return NULL;
	}
	PNode iterator = GetNodeInIndex(list, index);
	iterator->value = NULL;
	return iterator;
}

Node* Find(List* list, ListDataType value)
{
	if (list == NULL)
	{
		return NULL;
	}
	PNode iterator = list->root;
	while (iterator->next != NULL)
	{
		if (iterator->value == value)
		{
			return iterator;
		}

		iterator = iterator->next;
	}
	printf("%s", "Error: value match did not found");
	return NULL;
}