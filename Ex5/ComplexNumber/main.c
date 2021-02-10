/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/**
*         calculator of complex and real numbers
* @return 0 - when terminates
*/
#include "Union.h"

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
