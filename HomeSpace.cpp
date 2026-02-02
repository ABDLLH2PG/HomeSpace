#include <iostream>
#include <string>
#include <iomanip>
#include "MyUtilityLib.h"
using namespace std;

// [C07] Problem #03: Sum Each Row in Matrix in Array [My Solution]
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

int RowSum(int arr[3][3], short RowNumber, short Cols)
{
	int Sum = 0;
	for (short j = 0; j < Cols; j++)
	{
		Sum += arr[RowNumber][j];
	}

	return Sum;
}

void SumEachRowInArray(int arr[3][3], int arr1[3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		arr1[i] = RowSum(arr, i, Cols);
	}
}

void PrintEachRowSumInArray(int arr[3][3], int arr1[3], short Rows, short Cols)
{
	cout << "\n The following are the sum of each row in the matrix:\n";
	for (short i = 0; i < Rows; i++)
	{
		cout << " Row " << i + 1 << " Sum = " << arr1[i] << "\n";
	}
}

int main()
{
	MyUtilityLib::SeedRand();

	int arr[3][3];

	FillMatrixWithRandomNumbers(arr, 3, 3);

	cout << "\n The following is a 3x3 random matrix:\n";

	PrintMatrix(arr, 3, 3);

	int arr1[3];

	SumEachRowInArray(arr, arr1, 3, 3);

	PrintEachRowSumInArray(arr, arr1, 3, 3);

	return 0;
}