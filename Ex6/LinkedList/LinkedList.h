typedef int ListDataType;

typedef struct Node_t Node;

typedef struct List_t List;

List *CreateList();

void FreeList(List *list);

size_t GetListSize(List *list);

Node *GetListHead(List *list);

Node *GetNextNode(Node *currentNode);

ListDataType GetValue(Node *node);

Node *Insert(Node *after, ListDataType newValue);

Node *PushFront(List *list, , ListDataType newValue);

Node *PushBack(List *list, , ListDataType newValue);

ListDataType PopFront(List *list);

ListDataType PopBack(List *list);

void DeleteNode(List *list, Node * target);

Node *DeleteValue(List *list, , ListDataType value);

Node *Find(List *list, ListDataType value);
