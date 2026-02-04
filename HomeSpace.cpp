#include <iostream>
#include <string>
#include <iomanip>
#include "MyUtilityLib.h"

using namespace std;

// [C07] Problem #08: Multiply Two Matrices [My Solution]
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr[i][j] = MyUtilityLib::RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf(" %0*d     ", 2, arr[i][j]);
		}

		cout << "\n";
	}
}

void MultiplyTwoMatrices(int arr1[3][3], int arr2[3][3], int arrMultiply[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arrMultiply[i][j] = (arr1[i][j] * arr2[i][j]);
		}
	}
}

int main()
{
	int arr1[3][3], arr2[3][3], arrMultiply[3][3];

	FillMatrixWithRandomNumbers(arr1, 3, 3);
	FillMatrixWithRandomNumbers(arr2, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrix(arr1, 3, 3);

	cout << "\nMatrix2:\n";
	PrintMatrix(arr2, 3, 3);

	MultiplyTwoMatrices(arr1, arr2, arrMultiply, 3, 3);

	cout << "\nResults:\n";
	PrintMatrix(arrMultiply, 3, 3);


	return 0;
}