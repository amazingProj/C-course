#pragma once
#include "LinkedListUtils.h"
#include "Utils.h"

List * CreateList();

void FreeList(List* list);

size_t GetListSize(List* list);

Node * GetListHead(List* list);

Node * Insert(List *list, ListDataType value, size_t index);

Node * PushFront(List* list, ListDataType newValue);

Node* PushBack(List* list, ListDataType newValue);

Node * PopFront(List* list);

Node * PopBack(List* list);

void DeleteNodeFromList(List* list, size_t index);

Node * DeleteValue(List* list, size_t index);

Node * Find(List* list, ListDataType value);
