#include <stdio.h>
#include <stdbool.h>
/**
 * @brief checks if is not equal zero
 * @return boolean value.
 */
bool IsNotEqualZero(int num)
{
   return num == 0 ? true : false;
}
/**
 * @brief gets a number
 * @return the input number
 */
int GetNumber()
{
   int num;
   while (scanf("%d", &num) != 1)
   {
      while (getchar() != '\n');
      printf ("Try again: ");
   }
   return num;
}
/**
 *         Assumption: The user inputs at least three numbers
 * @brief  print the second smallest and biggest numbers
 * @return 0 - when terminates
 */
int main()
{
    int semiMaximum,maximum;
    int semiMinimum,minimum;
    printf("Enter two numbers");
    int num1,num2;

    num1 = GetNumber();
    num2 = GetNumber();

    if (num1 > num2)
    {
        semiMinimum = num1;
        semiMaximum = num2;
        maximum = num1;
        minimum = num2;
    }
    else
    {
        semiMinimum = num2;
        semiMaximum = num1;
        maximum = num2;
        minimum = num1;
    }

    printf("Enter a number");
    num1 = GetNumber();
    while (IsNotEqualZero(num1))
    {
         if (num1 < minimum)
        {
            semiMinimum = minimum;
            minimum = num1;
        }
        else
        {
            if (num1 < semiMinimum)
            {
                semiMinimum = num1;
            }
        }
       if (num1 > maximum)
       {
           semiMaximum = maximum;
           maximum = num1;
       }
       else
       {
           if(num1 > semiMaximum)
           {
               semiMaximum = num1;
           }
       }

    printf("Enter a number");
    num1 = GetNumber();

    }
    printf("second smallest : %d , second biggest : %d", semiMinimum, semiMinimum);
    return 0;
}
