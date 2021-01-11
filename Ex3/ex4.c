#include <stdio.h>

// contains later all fibonacci number untill 100
int array[100];

/**
 *  @param  index - the place of the fibonacci number
 *  @return the number in the n - place.
 */
int FibonacciNPlace(int index)
{
    return array[index];
}

/**
 * @brief  fibonacci numbers - //0,1,1,2,3,5
 *         Assumption fibonacci initial zero do not belong to series
 * @param  n - the series index. 
 * @return n th - number.
 */
int Fibonacci(int n)
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
 * checks the function and initialize the array.
 */
int main()
{
    for (int i = 0; i < 100; ++i)
    {
        array[i] = Fibonacci(i);
    }

    
    printf(" %d ", FibonacciNPlace(5));
    printf(" %d ", FibonacciNPlace(17));

    return 0;
}
