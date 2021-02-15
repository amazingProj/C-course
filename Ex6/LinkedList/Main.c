#include "LinkedList.h"
void AssertInsert(int x, int y)
{
	if (x == y)
	{
		printf("%s", "insert succeded\n");
	}
}
int main(void)
{
	List * list = CreateList();
	int x = 3;
	InitRoot(list, x);
	AssertInsert(x, list->root->value);
	x = 4;
	Insert(list, x, 1, 0);
	PNode node = PopFront(list);
	if (x == node->value)
	{
		printf("%s", "insert succeded\n");
	}
	Insert(list, x, 1, 0); Insert(list, x, 1, 0); Insert(list, x, 1, 0); 
	
	Insert(list, x, 1, 0); Insert(list, x, 1, 0); Insert(list, x, 1, 0); Insert(list, x, 1, 0);

	printf("%d", GetListSize(list));
	//FreeList(list); working
	PushFront(list, node, 1);
	return 0;
}