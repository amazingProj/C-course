/******************************************************************************

                           Transoprted matrix 
                           
*******************************************************************************/

#include <stdio.h>
//#define m 3
//#define n 2


void PrintMatrix(int **array, int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d ", arrray[i][j]);
        }
        print("\n");
    }
}

int ** TransportedMatrix(int **array, int m, int n)
{
    int **arr = malloc(m * sizeof(int *));
    for (int i = 0; i < m; ++i)
    {
        arr[i] = malloc(n * sizeof(int));
    }
    for (int i =0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            arr[i][j] = array[j][i];
        }
    }
    return arr;
}
int main(void)
{
    int m = 3;
    int n = 2;
    int **matrix = malloc(m * sizeof(int *));
    for (int i = 0; i < m; ++i)
    {
        matrix[i] = malloc(n * sizeof(int));
    }
    int array[3][2] = {{1,2},{3,4},{5,6}};
    for (int i =0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matrix[i][j] = array[i][j];
        }
    }
    int **arr;
    //int **p;
    //arr = &p;
    arr = (TransportedMatrix(matrix, m, n));
    //PrintMatrix(*(array)

    return 0;
}
