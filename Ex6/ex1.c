#include <stdio.h>
#include <stdbool.h>

/**
*    @param  number - an integer
*    @return true if it is bigger than zero, false if it is not.
*/
bool ValidInteger(int number)
{
	if (number > 0)
	{
		return true;
	}
	return false;
}

/**
*    
*    getting an integer from user 
*    @return the integer only if it is bigger than zero.
*/
int GettingNInteger()
{
	int num;
	while (scanf_s("%d", &num) != 1 && ValidInteger(num))
	{
		while (getchar() != '\n');
		printf("Try again: ");
	}
	return num;
}

/**
*    getting an integer fro user
*    @return the integer.
*/
int GettingInteger()
{
	int num;
	while (scanf_s("%d", &num) != 1)
	{
		while (getchar() != '\n');
		printf("Try again: ");
	}
	return num;
}


/**
*
* a program that reads a number n from the user, followed by n other numbers.
* The program will then print the numbers in reverse order.
* @return 0 - when terminated
*/
int main()
{
	printf("%s", "Enter a natural number\n");
	int num = GettingNInteger();
	
	int *array = malloc(num * sizeof(int));
	for (int i = 0; i < num; ++i)
	{
		printf("Interation number %d \n", i + 1);
		printf("Enter a number\n");
		array[i] = GettingInteger();
	}

	for (int j = num - 1; j >= 0; --j)
	{
		printf("%d ", array[j]);
	}

	return 0;
}
