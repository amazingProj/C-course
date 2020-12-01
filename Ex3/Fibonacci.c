#include <stdio.h>

/**
 * @brief  fibonacci numbers - //0,1,1,2,3,5
 *         Assumption fibonacci initial zero do not belong to series
 * @param  n - the series index. 
 * @return n th - number.
 */
int FibonacciNPlace(int n)
{
    int array[3] = {0,0,1};
    for (int i = 0; i < n; ++i)
    {
        array[0] = array[1] + array[2];
        array[1] = array[0];
    }
    return array[0];
}

/**
 * Checks the FibonacciNPlace function
 * @return 0 when finished
 */
int main(void)
{
    printf(" %d ", FibonacciNPlace(5));
    return 0;
}
