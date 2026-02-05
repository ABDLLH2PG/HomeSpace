#include <iostream>
#include <string>
#include "MyUtilityLib.h"
using namespace std;

// [C07] Problem #09: Print Middle Row and Col of Matrix [My Solution]
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

void PrintMiddleRowInMatrix(int arr[3][3], short Rows, short Cols)
{
	short MidRow = floor(Rows/ 2.0);

	for (int i = 0; i < Cols; i++)
	{
		printf(" %0*d     ", 2, arr[MidRow][i]);
	}

	cout << "\n";
}

void PrintMiddleColInMatrix(int arr[3][3], short Rows, short Cols)
{
	short MidCol = floor((Rows / 2.0));

	for (int i = 0; i < Rows; i++)
	{
		printf(" %0*d     ", 2, arr[i][MidCol]);
	}

	cout << "\n";
}

int main()
{
	MyUtilityLib::SeedRand();

	int arr[3][3];

	FillMatrixWithRandomNumbers(arr, 3, 3);

	cout << "Matrix1:" << endl;
	PrintMatrix(arr, 3, 3);

	cout << "\nMiddle Row of Matrix1 is:\n";
	PrintMiddleRowInMatrix(arr, 3, 3);

	cout << "\nMiddle Col of Matrix1 is:\n";
	PrintMiddleColInMatrix(arr, 3, 3);


	return 0;
}