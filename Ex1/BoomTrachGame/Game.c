#include "Game.h"


void BoomTrachGame(int number)
{
	for (int i = 1; i <= number; ++i)
	{
		// diveded by 3 and 5
		if (i % 3 == 0 && i % 5 == 0)
		{
			printf("%s\n", "Boom Trach");
			continue;
		}
		else
		{
			// only by 3
			if (i % 3 == 0)
			{
				printf("%s\n", "Boom ");
				continue;
			}
			// only by 5
			if (i % 5 == 0)
			{
				printf("%s\n", "Trach ");
				continue;
			}
		}

		// end digit is 3
		if (i % 10 == 3)
		{
			printf("%s\n", "Boom ");
			continue;
		}
	// non of above print only the number.
		printf("%d\n", i);
		
	}
}
