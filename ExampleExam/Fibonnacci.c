#include "Fibonacci.h"
#include <stdbool.h>
#include "malloc.h"

typedef struct DB_t
{
	unsigned long long *array;
	size_t size;
} DB, *PDB;

DB database;

bool firstTime = true;
unsigned long long Fibonacci(size_t n)
{
	if (firstTime)
	{
		database.size = 0;
	}
	firstTime = false;
	if (database.size < n)
	{
		unsigned long long *arr = malloc(n * sizeof(unsigned long long));

		for (size_t index = 0; index < database.size; ++index)
		{
			arr[index] = database.array;
		}
		//free(database.array);

		database.array = malloc(n * sizeof(unsigned long long));

		// copy all the values from arr to database.array
		for (size_t index = 0; index < n; ++index)
		{
			database.array[index] = arr[index];
		}
		database.size = n;

		free(arr);
	}
	else
	{
		if (database.array[n] != NULL)
		{
			return database.array[n];
		}
	}
	
	unsigned long long fib[] = { 0,0,1 };

	for (size_t index = 0; index < database.size; ++index)
	{
		fib[0] = fib[1] + fib[2];
		fib[1] = fib[2];
		fib[2] = fib[0];
	}
	
	database.array[n] = fib[2];

	// the resulting fibonnaci number
	return database.array[n];

}
