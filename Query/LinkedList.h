#pragma once
#include "LinkedListUtils.h"
#include "Utils.h"

/**
  * creates a list  
  * @return a new list
  * @warning if memory allocation failed returns NULL.
  *
  */
List * CreateList();

/**
  * deletes a list and free memory allocation
  * @param list - a list
  * @warning if list is NULL the end function
  *
  */
void FreeList(List* list);

/**
  * get list size
  * @param  list - a list
  * @return its size
  * @warning if list is NULL returns -1
  *
  */
size_t GetListSize(List* list);

/**
  * get list head 
  * @param list - a list
  * @return a root node of list
  * @warning if list is NULL returns NULL
  *
  */
Node * GetListHead(List* list);

/**
  * insert a ListDataType value to list
  * @param  list - a list
  * @param  value - a value 
  * @param  index - a index of place in list to insert
  * @return the inserted node
  * @see    GetNodeInIndex()
  * @attention assumption when error occured list is NULL.
  * @warning   cannot push to NULL.
  *
  */
Node * Insert(List *list, ListDataType value, size_t index);

/**
  * push a node to the front of list
  * @param  list - a list
  * @param  value - a value
  * @return the node that pushed
  * @see    Insert()
  * @attention when error occured returns NULL.
  * @warning   cannot push to NULL.
  *
  */
Node * PushFront(List* list, ListDataType value);

/**
  * push to the end of list
  * @param  list - a list
  * @param  value - a value
  * @return the node that pushed 
  * @see    Insert()
  * @attention when error occured returns NULL.
  * @warning   cannot push to NULL.
  *
  */
Node* PushBack(List* list, ListDataType value);

/**
  * pop the front of list e.g. return the front without deleteing it 
  * @param  list - a list
  * @return the first node
  * @attention when error occured returns NULL.
  * @warning   cannot pop from NULL list.
  *
  */
Node * PopFront(List* list);

/**
  * pop the back of list e.g. return the node in the end without deleteing it 
  * @param  list - a list
  * @return the last node 
  * @see functions: PopFront(), Insert()
  * @attention when error occured returns NULL.
  * @warning   cannot pop from NULL list.
  *
  */
Node * PopBack(List* list);

/**
  * deletes a node from a list
  * @param  list - a list
  * @param  index - a place of node to delete
  * @warning cannot deletes from NULL or index bigger than number of nodes in list.
  *
  */
void DeleteNodeFromList(List* list, size_t index);


/**
  * deletes only the value of Node in list
  * @param  list - a list
  * @param  index - a place of node to delete its value
  * @return pointer to that node 
  * @see    function: DeleteNodeFromList()
  * @attention when error occured returns NULL.
  * @warning   cannot deletes from NULL or index bigger than number of nodes in list.
  *
  */
Node * DeleteValue(List* list, size_t index);

/**
  * finds the first node with that value
  * @param  list - a list 
  * @param  value - a value
  * @return the founded node
  * @attention if nothing have been founded returns NULL or list is NULL
  *
  */
Node * Find(List* list, ListDataType value);
