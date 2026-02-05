#include <iostream>
#include <string>
#include <iomanip>
#include "MyUtilityLib.h"

using namespace std;

// [C07] Problem #11: Check Matrices Equality [My Solution]
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
			printf(" %0*d    ", 2, arr[i][j]);
		}

		cout << "\n";
	}
}

int SumOfMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	int Sum = 0;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Sum += Matrix1[i][j];
		}
	}

	return Sum;
}


int main()
{
	MyUtilityLib::SeedRand();

	int Matrix1[3][3], Matrix2[3][3];
	int SumOfMatrix1 = 0, SumOfMatrix2 = 0;

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	SumOfMatrix1 = SumOfMatrix(Matrix1, 3, 3);
	SumOfMatrix2 = SumOfMatrix(Matrix2, 3, 3);

	if (SumOfMatrix1 == SumOfMatrix2)
		cout << "\nYes: matrices are equal.\n";
	else
		cout << "\nNo: matrices are NOT equal.\n";


	system("pause>0");

	return 0;
}