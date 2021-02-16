#include <stdio.h>
#define len 15

int IsBegginWith(char *initialString, char *fullString)
{
	if (initialString == NULL || fullString == NULL)
	{
		return 0;
	}
	int i = 0;
	while (initialString[i] != NULL)
	{
		if (fullString[i] == NULL)
		{
			return 0;
		}
		if (initialString[i] != fullString[i])
		{
			return 0;
		}
		++i;
	}
	return 1;
}

int main(int argc, char *argv[], char *envp[])
{
	char *init = argv[1];

	size_t i = 0;
	while (envp[i] != NULL)
	{
		if (IsBegginWith(init, envp[i]))
		{
			printf("\n Enviromental variables %s", envp[i]);
		}
		++i;
	}

	return 0;
}