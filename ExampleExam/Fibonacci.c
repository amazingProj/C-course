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
unsigned long long Fibonacci(size_t t)
{
	size_t n = t - 1;
	unsigned long long *arr;
	if (firstTime)
	{
		arr = malloc(sizeof(unsigned long long));
		arr[0] = 0;
		database.array = malloc(sizeof(unsigned long long));
		database.array[0] = 0;
		database.size = 0;
	}
	firstTime = false;
	if (database.size < n)
	{
		arr = malloc(n * sizeof(unsigned long long));
		for (size_t index = 0; index < n; ++index)
		{
			arr[index] = 0;
		}

		for (size_t index = 0; index < database.size; ++index)
		{
			arr[index] = database.array[index];
		}
		free(database.array);

		database.array = malloc(n * sizeof(unsigned long long));

		for (size_t index = 0; index < n; ++index)
		{
			database.array[index] = 0;
		}

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
		if (database.array[n - 1] != NULL)
		{
			return database.array[n - 1];
		}
	}

	unsigned long long fib[] = { 0,0,1 };

	for (size_t index = 0; index < database.size; ++index)
	{
		fib[0] = fib[1] + fib[2];
		fib[1] = fib[2];
		fib[2] = fib[0];
	}

	database.array[n - 1] = fib[2];

	// the resulting fibonnaci number
	return database.array[n - 1];

}
