#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <stdbool.h>

#define STRING_SIZE 15

bool isReal;

typedef union ComplexNumber_t
{
	float complex[2];
	float real;

} ComplexNumber;

/**
* @brief gets a number
* @return the input number
*/
float GetNumber()
{
	float num;
	while (scanf_s("%f", &num) != 1)
	{
		while (getchar() != '\n');
		printf("Try again: ");
	}
	return num;
}

/**
*  Getting a char from user
*  @return a char
*/
char GettingOperator()
{
	printf("Enter operator: +, -, *, /, (any other chars to leave the program)\nYour choice: ");
	char operatorr;
	operatorr = getchar();
	getchar(); // You need to get the \n so it won't cause trouble when reading another char or string
	return operatorr;
}

/**
*   Getting a string, asks for real or complex
*   @return string
*/
char * GettingType()
{
	char *type = (char*)malloc(sizeof(*type) * STRING_SIZE);;
	printf("Enter number type: put: real or complex!\nYour choice: ");
	fgets(type, STRING_SIZE, stdin);
	return type;

}

/**
*   Getting a complex or real number
*   @param - type: real number or complex
*/
ComplexNumber GettingComplexNumber(char* type)
{
	ComplexNumber result;
	result.complex[0] = 0.0;
	result.complex[1] = 0.0;
	result.real = 0.0;
	if (!strcmp(type, "real\n"))
	{
		printf("Enter a real number: \n");
		result.real = GetNumber();
		if (!isReal)
		{
			isReal = true;
		}
		
	}

	if (!strcmp(type, "complex\n"))
	{
		printf("Enter a real number for the real part: ");
		result.complex[0] = GetNumber();
		printf("Enter a real number for the imaginary part: ");
		result.complex[1] = GetNumber();
		isReal = false;

	}
	getchar(); // since you are reading a char as operator you need to catch the '\n' here also
	return result;
}

/**
*   @param num1 -  a complex number a + bi
*   @param num2 - a commplex number c + di
*
*   @return num1 / num2
*   formula: (ac + bd) / (c^2 + d^2) + i((bc - ad) / (c^2 + d^2))
*/
ComplexNumber Devision(ComplexNumber num1, ComplexNumber num2)
{
	ComplexNumber result;
	float denominator = num2.complex[0] * num2.complex[0] + num2.complex[1] * num2.complex[1];
	result.complex[0] = (num1.complex[0] * num2.complex[0] + num1.complex[1] * num2.complex[1]) /
		denominator;
	result.complex[1] = (num1.complex[2] * num2.complex[1] - num1.complex[0] * num2.complex[1]) /
		denominator;
	return result;

}

/**
*  @param num1 - a + bi
*  @param num2 - c + di
*  @return a complex number
*  formula:  ac - bd + i(ad + bc)
*/
ComplexNumber Multiplicate(ComplexNumber num1, ComplexNumber num2)
{
	ComplexNumber result;
	result.complex[0] = num1.complex[0] * num2.complex[0] - num1.complex[1] * num2.complex[1];
	result.complex[1] = num1.complex[0] * num2.complex[1] + num1.complex[1] * num2.complex[0];
	return result;

}

/**
*
*  @param num1 - a complex number
*  @param num2 - a complex number
*
*  @return num1 - num2 in a complex number
*/
ComplexNumber OperatorMinus(ComplexNumber num1, ComplexNumber num2)
{
	ComplexNumber result;
	result.complex[0] = num1.complex[1] - num2.complex[0];
	result.complex[1] = num1.complex[1] - num2.complex[1];
	return result;

}

/**
*  adding two complex numbers.
*  @param num1 - a complex nnumber
*  @param num2 - a complex number
*
*/
ComplexNumber OperatorPlus(ComplexNumber num1, ComplexNumber num2)
{
	ComplexNumber result;
	result.complex[0] = num1.complex[0] + num2.complex[0];
	result.complex[1] = num1.complex[1] + num2.complex[1];
	return result;

}

void PrintComplexNumber(ComplexNumber num)
{
	if (isReal)
	{
		printf("%.2f\n", num.real);
	}
	else
	{
		if (num.complex[1] >= 0.0)
		{
			printf("%.2f + %.2fi\n", num.complex[0], num.complex[1]);
		}
		else
		{
			printf("%.2f - %.2fi\n", num.complex[0], -num.complex[1]);
		}
	}
	
}

/**
*         calculator of complex and real numbers
* @return 0 - when terminates
*/
int main()
{
	char *type;
	type = GettingType();
	ComplexNumber num1 = GettingComplexNumber(type);

	char operatorr;
	int ext = 0;
	ComplexNumber num2;

	while (ext == 0)
	{
		operatorr = GettingOperator();

		//If the user didn't type one of the operators below then break the loop
		if (!strchr("+-/*", operatorr))
			break;
		type = GettingType();
		num2 = GettingComplexNumber(type);
		switch (operatorr)
		{
		case '+':
			num1 = OperatorPlus(num1, num2);
			break;
		case '*':
			num1 = Multiplicate(num1, num2);
			break;
		case '/':
			num1 = Devision(num1, num2);
			break;
		case '-':
			num1 = OperatorMinus(num1, num2);
			break;
		}
	}

	PrintComplexNumber(num1);
	free(type);
	return 0;
}
