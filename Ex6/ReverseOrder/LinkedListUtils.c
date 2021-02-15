#include "LinkedListUtils.h"

void DeleteNode(PNode node)
{
	free(node->next);
	free(node->prev);
}

PNode GetNodeInIndex(List* list, size_t index)
{
	PNode iterator = list->root;
	for (size_t i = 0; i < index; ++i)
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
	list->root->value = value;
	return list->root;
}