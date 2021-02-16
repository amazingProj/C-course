#include "Utils.h"

int EqualsDouble(double number1, double number2)
{
	return fabs(number1 - number2) > Eps ? 1 : 0;
}