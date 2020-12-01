#include <stdio.h>

/**
 * @brief  get an array of integers and prints the sum of them
 * @param  array -  array of integers
 * @param  the size of array
 * @return the sum of them 
 */
int Sum(int array[], int size)
{
    int result;
    for (int i = 0; i < size; ++i)
    {
        result += array[i];
    }
    return result;
}

/**
 * Checks the Sum function
 * @return 0 when finished
 */
int main(void)
{
    int array[]={1,2,3,4,5};
    int size = sizeof array / sizeof *array;
    printf("%d",Sum(array,size));
    return 0;
}
