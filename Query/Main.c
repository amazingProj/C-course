#include "Query.h"

void PrintTestResult(size_t x, int code)
{
	if (code == 1)
	{
		printf("%13d %10s\n", x, "Succeded");
	}
	else
	{
		printf("%13d %10s\n", x, "Failed");
	}

}
int main(void)
{
	printf("%13s %10s \n", "Test number", "Result");

	Query *query = CreateQuery();

	PNode node = (PNode)(malloc(sizeof(Node)));
	int x = 190;
	node->value = x;
	QueryPush(query, node);

	x = 1908;
	node->value = x;
	QueryPush(query, node);

	x = 19023;
	node->value = x;
	QueryPush(query, node);

	x = 12;
	node->value = x;
	QueryPush(query, node);

	x = 121;
	node->value = x;
	QueryPush(query, node);

	x = 8;
	node->value = x;
	QueryPush(query, node);

	QueryPrint(query);

	PrintTestResult(1, 1);
	
	DeleteQuery(query);
	
	PrintTestResult(2, 1);
	
	return 0;
}
