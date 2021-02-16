/******************************************************************************

                           Transoprted matrix 
                           
*******************************************************************************/

#include <stdio.h>

_Bool results[2] = { 1, 1 };

void MatrixTypeByResults(int **array, int n)
{
	if (array == NULL)
	{
		return;
	}

	if (results[0])
	{
		printf("%23s", "The matrix is symetrix");
		return;
	}

	if (results[1])
	{
		printf("%23s", "The matrix is skew symetrix");
		return;
	}

	printf("%23s", "ordinary matrix");
}

void PrintMatrix(int **array, int m, int n)
{
	if (array == NULL)
	{
		return;
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}

int ** TransportedMatrix(int **array, int n)
{
	int **arr = malloc(n * sizeof(int *));
	for (int i = 0; i < n; ++i)
	{
		arr[i] = malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (array[i][j] != array[j][i])
			{
				results[0] = 0;
			}
			if (i != j)
			{
				if (array[i][j] != -array[j][i])
				{
					results[1] = 0;
				}
			}

			arr[i][j] = array[j][i];
		}
	}
	return arr;
}

int main(void)
{
	int n = 3;
	int **matrix = malloc(n * sizeof(int *));
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = malloc(n * sizeof(int));
	}
	int array[3][3] = { { 1, -3, -5 },{ 3, 4, -6 },{ 5, 6, 8998 } };
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			matrix[i][j] = array[i][j];
		}
	}
	int **arr;
	arr = (TransportedMatrix(matrix, n));
	PrintMatrix(arr, n, n);
	MatrixTypeByResults(arr, n);

	return 0;
}
