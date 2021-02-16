#pragma once
#pragma once
#include "LinkedList.h"

/**
* class represents query
*/
typedef struct Query_t
{
	PNode root;
	List *list;
} Query;

/**
* creates a query
* @return a new query
* @see function: CreateList()
*
*/
Query *CreateQuery();

/**
* deletes a query
* @param  query - a query
* @attention function is closed to query is null
*
*/
void DeleteQuery(Query *query);

/**
* push a new node to a query
* @param  stack - a stack
* @param  item - an node item
* @see function: PushFront()
*
*/
void QueryPush(Query *query, PNode item);

/**
* pop the top of the query
* @param  stack - a query
* @return the poped node
* @see PopFront()
* @warning the same as PopFront function
*
*/
Node *QueryPop(Query *query);

/**
* if query is empty
* @param  query - a query
* @return 1 if query is empty, 0 if it is not
*
*/
int QueryGetLastError(Query *query);

/**
* get the size of query
* @param stack - a query
* @return the size of the query
* @see GetListSize()
* @warning the same as the function below
*
*/
size_t QuerySize(Query *query);

/**
 * prints a query
 * @param query - a query
 *
 */
void QueryPrint(Query *query);

