#include "LinkedList.h"
void AssertInsert(int x, int y)
{
	if (x == y)
	{
		printf("%s", "insert succeded\n");
	}
}

void PrintTestResult(size_t x, int code)
{
	if (code == 1)
	{
		printf("%11d %10s\n", x, "Succeded");
	}
	else
	{
		printf("%11d %10s\n", x, "Failed");
	}
	
}
int main(void)
{
	printf("%11s %10s \n", "Test number", "Result");
	List * list = CreateList();
	int x = 3;
	//AssertInsert(x, list->root->value);
	x = 4;
	Insert(list, x, 0);
	
	Insert(list, x, 1); Insert(list, x, 1); Insert(list, x, 1);

	Insert(list, x, 1); Insert(list, x, 1); Insert(list, x, 1); Insert(list, x, 1);

	if (GetListSize(list) == 8)
	{
		//succeded
		PrintTestResult(1, 1);
	}
	else
	{
		PrintTestResult(1, 0);
	}
	//printf("%d", GetListSize(list));
	//FreeList(list); is working
	
	x = 100;
	PushFront(list, x);
	PNode node = PopFront(list);
	if (x == node->value)
	{
		PrintTestResult(2, 1);
	}
	else
	{
		PrintTestResult(2, 0);
	}

	x = 3090;
	PushBack(list, x);
	node = PopBack(list);
	if (x == node->value)
	{
		PrintTestResult(3, 1);
	}
	else
	{
		PrintTestResult(3, 0);
	}

	Insert(list, 90288, GetListSize(list));
	PushBack(list, x);
	x = 3090;
	PopBack(list);
	node = PopBack(list);
	if (90288 == node->value)
	{
		PrintTestResult(4, 1);
	}
	else
	{
		PrintTestResult(4, 0);
	}

	DeleteNodeFromList(list, GetListSize(list) - 1);
	node = Find(list, 90288);
	if (node == NULL)
	{
		PrintTestResult(5, 1);
	}
	else
	{
		PrintTestResult(5, 0);
	}
	node = Find(list, 3090);
	if (node != NULL)
	{
		PrintTestResult(6, 1);
	}
	else
	{
		PrintTestResult(6, 0);
	}
	return 0;
}