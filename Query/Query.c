#include "Query.h"

/**
  * @file Query.h
  */
Query *CreateQuery()
{
	Query *query = (Query *)(malloc(sizeof(Query)));
	query->list = CreateList();
	query->root = GetListHead(query->list);

	return query;
}

void DeleteQuery(Query *query)
{
	FreeList(query->list);
	free(query);
}

void QueryPush(Query *query, PNode item)
{
	PushBack(query->list, item->value);
	query->root = GetListHead(query->list);
}

Node *QueryPop(Query *query)
{
	return PopFront(query->list);
	query->root = GetListHead(query->list);
}

int QueryGetLastError(Query *query)
{
	return (query->list == NULL);
}

size_t QuerySize(Query *query)
{
	return GetListSize(query);
}

void QueryPrint(Query *query)
{
	printf("%13s  %6s\n", "serial number", "values");
	PNode iterator = query->root;
	for (size_t i = 0; i < query->list->sizeOfList; ++i)
	{
		if (iterator->value != NULL)
		{
			printf("%13d  %6d\n", i, iterator->value);
		}
		iterator = iterator->next;
	}
}

