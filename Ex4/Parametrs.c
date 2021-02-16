#include <stdio.h>

int IsUppercase(char *str)
{
	int i = 0;
	while (str[i] != NULL)
	{
		if (!(str[i] >= 'A' &&  str[i] <= 'Z'))
		{
			return 0;
		}
		++i;
	}
	return 1;
}

int IsLowercase(char *str)
{
	int i = 0;
	while (str[i] != NULL)
	{
		if (!(str[i] >= 'a' &&  str[i] <= 'z'))
		{
			return 0;
		}
		++i;
	}
	return 1;
}

int Equals(char *str1, char *str2)
{
	int i = 0;
	while (str1[i] != NULL && str2[i] != NULL)
	{
		if (str1[i] != str2[i])
		{
			return 0;
		}
		++i;
	}
	return 1;
}

int main(int argc, char *argv[])
{
	for (size_t i = 0; i < argc; ++i)
	{
		printf("%10s %d is %15s\n", "Parameter", i, argv[i]);
	}

	printf("The number of all paraametrs is %d\n", argc);

	int switches = 0, uppercasesCounter = 0, lowercasesCounter = 0;
	for (size_t i = 0; i < argc; ++i)
	{
		if (Equals(argv[i], "-help") || Equals(argv[i], "/s"))
		{
			++switches;
		}

		if (IsUppercase(argv[i]))
		{
			++uppercasesCounter;
		}
		if (IsLowercase(argv[i]))
		{
			++lowercasesCounter;
		}
	}

	printf("%s %d \n%s %d \n%s %d \n", "The number of switches is the number", switches, "The number of uppercases is the number",
		 uppercasesCounter, "The number of lowercases is the number", lowercasesCounter);

	return 0;
}