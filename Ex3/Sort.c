#include <stdio.h>
/**
 * @brief insertion sort algorithm
 * @param arr of array of integers
 * @param n size of the array
 */
void Sort(int *arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
/**
 * Checks the Sort function
 * @return 0 when finished
 */
int main(void)
{
    int array[]={5,6,7,1,2,55,3,6,8};
    int size = sizeof array / sizeof *array;
    Sort(&array,size);
    printf(" maximum %d, minimum %d ", *array, array[size]);
    return 0;
}
