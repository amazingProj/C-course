#include <stdio.h>

// later in code: contains all fibonacci number untill 100
int fibonacci[100];

/**
 * @brief  fibonacci numbers - //0,1,1,2,3,5
 *         Assumption fibonacci initial zero do not belong to series
 * @param  n - the series index. 
 * @return n th - number.
 */
int FibonacciNPlace(int n)
{
    if (n > 100)
    {
        return 0;
    }
    
    return fibonacci[n-1];
}

/**
 * Checks the FibonacciNPlace function
 * @return 0 when finished
 */
int main(void)
{
    int array[3] = {0,0,1};
    for (int i = 0; i < 100; ++i)
    {
        array[0] = array[2];
        array[2] = array[1] + array[2];
        array[1] = array[0];
        fibonacci[i] = array[0];
    }
    
    printf(" %d ", FibonacciNPlace(17));
    return 0;
}
