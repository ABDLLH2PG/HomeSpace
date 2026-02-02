#include <iostream>
#include <string>
#include <iomanip>
#include "MyUtilityLib.h"
using namespace std;

//[C07] Problem #02: Sum Each Row in Matrix [Optimized Code]
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

void PrintEachRowSum(int arr[3][3], short Rows, short Cols)
{
	cout << "\n The following are the sum of each row in the matrix:\n";
	for (short i = 0; i < Rows; i++)
	{
		cout << " Row " << i + 1 << " Sum = " << RowSum(arr, i, Cols) << "\n";
	}
}

int main()
{
	MyUtilityLib::SeedRand();

	int arr[3][3];

	FillMatrixWithRandomNumbers(arr, 3, 3);

	cout << "\n The following is a 3x3 random matrix:\n";

	PrintMatrix(arr, 3, 3);

	PrintEachRowSum(arr, 3, 3);


	return 0;
}