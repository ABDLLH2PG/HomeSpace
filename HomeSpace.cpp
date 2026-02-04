#include <iostream>
#include <string>
#include <iomanip>
#include "MyUtilityLib.h"

using namespace std;

// [C07] Problem #08 Multiply Two Matrices [Optimized Code]
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

void MultiplyTwoMatrices(int Matrix1[3][3], int Matrix2[3][3], int MatrixResults[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			MatrixResults[i][j] = (Matrix1[i][j] * Matrix2[i][j]);
		}
	}
}

int main()
{
	MyUtilityLib::SeedRand();

	int Matrix1[3][3], Matrix2[3][3], MatrixResults[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	MultiplyTwoMatrices(Matrix1, Matrix2, MatrixResults, 3, 3);

	cout << "\nResults:\n";
	PrintMatrix(MatrixResults, 3, 3);

	system("pause>0");

	return 0;
}