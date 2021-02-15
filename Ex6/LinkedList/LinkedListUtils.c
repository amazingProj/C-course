#include "LinkedListUtils.h"

void DeleteNode(PNode node)
{
	free(node->next);
	free(node->prev);
	free(node->value);
}

PNode GetNodeInIndex(List* list, size_t index)
{
	PNode iterator = list->root;
	for (size_t i = 0; i < index; ++i)
	{
		if (iterator->next == NULL)
		{
			printf("%s", "Error: there is no such index");
			return;
		}
		iterator = iterator->next;
	}
	return iterator;
}

void InitRoot(List* list, T value)
{
	list->root->value = value;
}