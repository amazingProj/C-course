#pragma once
#include "LinkedListUtils.h"
#include "Utils.h"

List * CreateList();

void FreeList(List* list);

size_t GetListSize(List* list);

Node * GetListHead(List* list);

ListDataType GetValue(List *list);

Node * Insert(List *list, T value, ListDataType newValue, size_t index);

Node * PushFront(List* list, Node* after, ListDataType newValue);

Node* PushBack(List* list, Node* after, ListDataType newValue);

Node * PopFront(List* list);

Node * PopBack(List* list);

void DeleteNodeFromList(List* list, size_t index);

Node * DeleteValue(List* list, size_t index);

Node * Find(List* list, T value);