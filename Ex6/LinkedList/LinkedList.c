#include "LinkedList.h"

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
	list->dataType = NULL;
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
	free(list->dataType);
	while (list->root->next != NULL)
	{
		free(list->root->value);
		free(list->root->prev);
		list->root = list->root->next;
		free(list->root->next);
	}
	free(list->root);
	free(list->dataType);
	free(list->sizeOfList);
}

size_t GetListSize(List *list)
{
	if (list->sizeOfList != NULL)
	{
		return list->sizeOfList;
	}
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


ListDataType GetValue(List *list)
{
	list->dataType;
}

Node* Insert(List* list, T value, ListDataType newValue, size_t index)
{
	List* newList = list;
	if (list == NULL)
	{
		 newList = CreateList();
	}
	//if there is no data type
	if (newList->dataType == NULL)
	{
		newList->dataType = newValue;
	}
	else {
		if (newValue != newList->dataType)
		{
			printf("Error: list's typecode does not match the given code\n");
			return NULL;
		}
	}
		
	PNode iterator = GetNodeInIndex(newList, index);


	PNode newNode = (PNode)(malloc(sizeof(Node)));
	newNode->value = value;
	newNode->prev = iterator;

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
	return newNode;
}

Node* PushFront(List* list, Node* after, ListDataType newValue)
{
	Insert(list, after, newValue, 0);
}

Node* PushBack(List* list, Node* after, ListDataType newValue)
{
	Insert(list, after, newValue, GetListSize(list));
}

Node * PopFront(List* list)
{
	list->root = list->root->next;
	return list->root->prev;
}

Node* PopBack(List* list)
{
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
	PNode iterator = GetNodeInIndex(list, index);
	iterator->prev->next = iterator->next;
	iterator->next->prev = iterator->prev->next;
	DeleteNode(iterator);
}

Node* DeleteValue(List* list, size_t index)
{
	PNode iterator = GetNodeInIndex(list, index);
	iterator->value = NULL;
}

Node* Find(List* list, T value)
{
	PNode iterator = list->root;
	while (iterator->next != NULL)
	{
		if (list->dataType )
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