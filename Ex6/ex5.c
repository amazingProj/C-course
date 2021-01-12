#include <stdio.h>
#include <stdbool.h>

/**
*    
*    checks if string is an integer
*    @param  str - a string
*    @return the integer only if it is bigger than zero.
*/
int IsNumber(char *str)
{
	int index = 0;
	while (strcmp(str[index], '/0'))
	{
		if (isdigit(str[index]) == false)
		{
			return false;
		}
		return true;
	}
}

/**
*    getting an string from user
*    @return the integer.
*/
char * GettingString()
{
	char *num;
	while (scanf_s("%s", &num) != 1)
	{
		while (getchar() != '\n');
		printf("Try again: ");
	}
	return num;
}


/**
*
* program that receives an unknown number of numbers from the user. 
* Input from the user ends when the user types a non-numeric string.
* @return 0 - when terminated
*/
int main()
{

	printf("Enter a number or any other string to exit\n");
	char **number = GettingString();
	int iterationIndex = 1;
	
	while (IsNumber(number))
	{
		printf("Interation number %d \n", iterationIndex + 1);
		printf("Enter a number or any other string to exit\n");
		++number;
		*number = GettingString();
		

	} 

	for (int j = iterationIndex - 1; j >= 0; --j)
	{
		printf("%d ", *(--number));
	}

	return 0;
}
