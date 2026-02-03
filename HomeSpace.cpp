#include <iostream>
#include <string>
#include <iomanip>
#include "MyUtilityLib.h"
using namespace std;

// [C07] Problem #05 Sum Each Cols in Matrix In Another Array [Optimized Code]
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr[i][j] = MyUtilityLib::RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		}

		cout << endl;
	}
}

int ColSum(int arr[3][3], short Rows, short ColNumber)
{
	int Sum = 0;

	for (short i = 0; i < Rows; i++)
	{
		Sum += arr[i][ColNumber];
	}

	return Sum;
}

void SumMatrixColsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
	for (int i = 0; i < Cols; i++)
	{
		arrSum[i] = ColSum(arr, Rows, i);
	}
}

void PrintColSumArray(int arrSum[3], short Cols)
{
	cout << "\n The following are the sum of each col in the matrix:\n";

	for (int j = 0; j < Cols; j++)
	{
		cout << " Col " << (j + 1) << " Sum = " << arrSum[j] << "\n";
	}

	cout << endl;
}


int main()
{
	MyUtilityLib::SeedRand();

	int arr[3][3];

	FillMatrixWithRandomNumbers(arr, 3, 3);

	cout << "\n The following is a 3x3 random matrix:\n";

	PrintMatrix(arr, 3, 3);

	int arrSum[3];

	SumMatrixColsInArray(arr, arrSum, 3, 3);

	PrintColSumArray(arrSum, 3);



	return 0;
}