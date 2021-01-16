#include "Game.h"

/**
 * checks the function implementation in Game.c and interact with the user
 * @return 0 - when terminates.
 */
int main(void)
{
	int num;

	printf("%s", "Please enter a number: ");

	while (scanf_s("%d", &num) != 1)
	{
		while (getchar() != '\n');
		printf("Try again: ");
	}
	
	BoomTrachGame(num);


	return 0;
}
