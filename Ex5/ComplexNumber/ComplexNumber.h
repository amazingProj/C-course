#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <stdbool.h>

#define STRING_SIZE 15

bool isReal;

typedef struct ComplexNumber2_t
{
    double real;
    double image;
} ComplexNum;
typedef union ComplexNum_t
{
    ComplexNum cmp;
    double number;
} ComplexNUM;
typedef struct Number_t
{
     ComplexNUM number;
    _Bool isNumber;
} Nuber;

typedef union ComplexNumber_t
{
	float complex[2];
	float real;

} ComplexNumber;

/**
* @brief gets a number
* @return the input number
*/
float GetNumber();

/**
*  Getting a char from user
*  @return a char
*/
char GettingOperator();

/**
*   Getting a string, asks for real or complex
*   @return string
*/
char * GettingType();
/**
*   Getting a complex or real number
*   @param - type: real number or complex
*/
ComplexNumber GettingComplexNumber(char* type);

/**
 * formula: (ac + bd) / (c^2 + d^2) + i((bc - ad) / (c^2 + d^2))
 * 
 *   @param num1 -  a complex number a + bi
 *   @param num2 - a commplex number c + di
 *
 *   @return num1 / num2
 *   
 */
ComplexNumber Devision(ComplexNumber num1, ComplexNumber num2);

/**
*  @param num1 - a + bi
*  @param num2 - c + di
*  @return a complex number
*  formula:  ac - bd + i(ad + bc)
*/
ComplexNumber Multiplicate(ComplexNumber num1, ComplexNumber num2);
/**
*
*  @param num1 - a complex number
*  @param num2 - a complex number
*
*  @return num1 - num2 in a complex number
*/
ComplexNumber OperatorMinus(ComplexNumber num1, ComplexNumber num2);

/**
*  adding two complex numbers.
*  @param num1 - a complex nnumber
*  @param num2 - a complex number
*
*/
ComplexNumber OperatorPlus(ComplexNumber num1, ComplexNumber num2);

void PrintComplexNumber(ComplexNumber num);
