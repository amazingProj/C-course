#include "LinkedListUtils.h"
/**
  * @file LinkedListUtils.h
  */
void DeleteNode(PNode node)
{
	if (node == NULL)
	{
		return;
	}

	free(node->next);
	free(node->prev);
}

PNode GetNodeInIndex(List* list, size_t index)
{
	if (list == NULL)
	{
		return NULL;
	}

	PNode iterator = list->root;
	for (size_t i = 1; i < index; ++i)
	{
		if (iterator->next == NULL)
		{
			printf("%s", "Error: there is no such index\n");
			return NULL;
		}

		iterator = iterator->next;
	}
	return iterator;
}

PNode InitRoot(List* list, ListDataType value)
{
	if (list == NULL)
	{
		return NULL;
	}

	list->root->value = value;
	return list->root;
}