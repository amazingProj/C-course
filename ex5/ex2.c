#include <stdio.h>
typedef struct ComplexNumber_S
{
    float realNumber;
    float img;
} ComplexNumber;


void PrintComplexNumber(ComplexNumber num)
{
    if (num.img > 0.0)
    {
         printf("%.2f + %.2fi",num.realNumber,num.img);
    }
   else
   {
        printf("%.2f  %.2fi",num.realNumber,num.img);
   }
}

/**
 * @brief gets a number
 * @return the input number
 */
float GetNumber()
{
   float num;
   while (scanf("%f", &num) != 1)
   {
      while (getchar() != '\n');
      printf ("Try again: ");
   }
   return num;
}

/**
 *         calculator of complex and real numbers
 * @return 0 - when terminates
 */
int main()
{
    ComplexNumber cmp3;
    cmp3.realNumber = 0.0;
    cmp3.img = 0.0;
    int number2 = 0;
    ComplexNumber cmp2;
    ComplexNumber cmp;
    int formerIndex;
    float number;
    printf("Enter number type: put: real or complex!\n");
    char* type;
    scanf("%s", type);
    if (type == "real")
    {
        number = GetNumber();
        formerIndex = 0;
    }
    if (type == "complex")
    {
        printf("Enter real number");
        cmp.realNumber = GetNumber();
        printf("Enter image field");
        cmp.img = GetNumber();
        formerIndex = 1;

    }

    
    printf("Enter operator: +, -, *, /, any other chars \n");
    int ext = 0;
    char operator;
    operator = getchar();

    while (ext == 0)
    {
        switch (operator)
        {
        case '+':
        printf("Enter number type: put: real or complex!/n");
        char* type;
        scanf("%s", type);
        if (type == "real")
        {
        number2 = GetNumber();
        formerIndex = 0;
        if (formerIndex == 1)
        {
            cmp3.realNumber += cmp.realNumber;
            cmp3.img += cmp.img;
            PrintComplexNumber(cmp3);
        }
        else
        {
            number2 += number;
            printf("%d", number2);
        }
        }
        if (type == "complex")
        {
        printf("Enter real field");
        cmp2.realNumber = GetNumber();
        printf("Enter image field");
        cmp2.img = GetNumber();
        
        if (formerIndex == 1)
        {
            cmp3.realNumber += cmp2.realNumber;
            cmp3.img += cmp2.img;
            PrintComplexNumber(cmp3);
        }
        else
        {
            cmp2.realNumber += number;
            PrintComplexNumber(cmp2);
        }
        

        }

        
    
            break;
        case '*':
            break;
        case '/':
            break;
        case '-':
            break;
        default:
            ext = 1;
            break;

        }
    }





    printf("Hello, World!\n");
    return 0;
}
