#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define STRING_SIZE 15

typedef struct ComplexNumber_S
{
	float realNumber;
	float img;
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
char* GettingType()
{
	char* type = (char*)malloc(sizeof(*type) * STRING_SIZE);;
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
	result.realNumber = 0.0;
	result.img = 0.0;
	if (!strcmp(type, "real\n"))
	{
		printf("Enter a real number: \n");
		result.realNumber = GetNumber();
		result.img = 0.0;
	}

	if (!strcmp(type, "complex\n"))
	{
		printf("Enter a real number for the real part: ");
		result.realNumber = GetNumber();
		printf("Enter a real number for the imaginary part: ");
		result.img = GetNumber();

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
	float denominator = num2.realNumber * num2.realNumber + num2.img * num2.img;
	result.realNumber = (num1.realNumber * num2.realNumber + num1.img * num2.img) /
		denominator;
	result.img = (num1.img * num2.realNumber - num1.realNumber * num2.img) /
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
	result.realNumber = num1.realNumber * num2.realNumber - num1.img * num2.img;
	result.img = num1.realNumber * num2.img + num1.img * num2.realNumber;
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
	result.realNumber = num1.realNumber - num2.realNumber;
	result.img = num1.img - num2.img;
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
	result.realNumber = num1.realNumber + num2.realNumber;
	result.img = num1.img + num2.img;
	return result;

}

void PrintComplexNumber(ComplexNumber num)
{
	if (num.img >= 0.0)
	{
		printf("%.2f + %.2fi\n", num.realNumber, num.img);
	}
	else
	{
		printf("%.2f - %.2fi\n", num.realNumber, -num.img);
	}
}

/**
*         calculator of complex and real numbers
* @return 0 - when terminates
*/
int main()
{
	char* type;
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
