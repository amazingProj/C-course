#include "Fibonacci.h"
#include <stdbool.h>

bool firstPrinting = true;

void PrintFibonnaciNumber(unsigned long long fib, size_t index)
{
	if (firstPrinting)
	{
		printf("%16s  %11s\n", "Place in series", "The number");
	}
	printf("%16d  %11d \n", index, fib);

	firstPrinting = false;
}


int main(void)
{
	size_t index = 2;
	unsigned long long fib = Fibonacci(index);
	PrintFibonnaciNumber(fib, index);

	index = 3;
	fib = Fibonacci(index);
	PrintFibonnaciNumber(fib, index);

	index = 6;
	fib = Fibonacci(index);
	PrintFibonnaciNumber(fib, index);

	index = 7;
	fib = Fibonacci(index);
	PrintFibonnaciNumber(fib, index);

	index = 22;
	fib = Fibonacci(index);
	PrintFibonnaciNumber(fib, index);

	index = 29;
	fib = Fibonacci(index);
	PrintFibonnaciNumber(fib, index);

	index = 54;
	fib = Fibonacci(index);
	PrintFibonnaciNumber(fib, index);

	index = 29;
	fib = Fibonacci(index);
	PrintFibonnaciNumber(fib, index);

	index = 60;
	fib = Fibonacci(index);
	PrintFibonnaciNumber(fib, index);
	return 0;
}
/*
 
 Example: test's output
 
 Place in series   The number
               2            1
               3            2
               6            8
               7           13
              22        17711
              29       514229
              54    368225352
              29       514229
              60   1820529360

*/
