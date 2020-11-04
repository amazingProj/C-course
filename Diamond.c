#include <stdio.h>
#include<stdbool.h>

/**
 * @brief check if number is odd
 * @param number - an integer number
 * @return boolean variable if is it odd
 */
bool IsNumberOdd(const int number);

/**
 * prints diamond by using asterisks. 
 * @param number - an iteger number
 * @return boolean variable whether he can build or not.
 */
bool DiamondOfAsterisks(const int number);

int main()
{
    bool withoutAnyError;
    withoutAnyError = DiamondOfAsterisks(11);
    return withoutAnyError;
}

/******* Implementation of functions *******/

bool DiamondOfAsterisks(const int number)
{
    if (!IsNumberOdd(number))
        return false;//meaning he cannot build by this number a diamond 
    const int spaceIndex = (int) (number / 2 - 1) ;
    int reducer = 0;
    int asterisksIndex = 1;
    for (int i = 0;i <= number / 2;++i)
    {
       for(int j = 0;j <= (spaceIndex - reducer);++j)
       {
           printf("%s"," ");
       }
       for (int l = 0;l < asterisksIndex;++l)
       {
           printf("%s","*");
       }
       ++reducer;
       asterisksIndex += 2;
       printf("\n");
    }
    reducer = 0;
    asterisksIndex -= 2;
    for (int i = number;i > 0;--i)
    {
        asterisksIndex -= 2;
        ++reducer;
        for (int j = 0;j < reducer;++j)
        {
            printf("%s"," ");
        }
       
        for (int l = 0;l < asterisksIndex;++l)
        {
            printf("%s","*");
        }
        printf("\n");
    }
    return true;
}

bool IsNumberOdd(const int number)
{
   bool i = false;
   if (number % 2 == 1)
       i = true;
   return i;
}

