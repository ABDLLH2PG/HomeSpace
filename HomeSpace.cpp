#include <iostream>
#include <string>
#include <iomanip>
#include "MyUtilityLib.h"

using namespace std;

// [C07] Problem #14: Check Scalar Matrix [Optimized Code]
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		}

		cout << "\n";
	}
}

bool IsScalarMatrix(int Matrix[3][3], short Rows, short Cols)
{
	int FirstDiagElement = Matrix[0][0];

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (i == j && Matrix[i][j] != FirstDiagElement)
			{
				return false;
			}

			else if (i != j && Matrix[i][j] != 0)
			{
				return false;
			}
		}
	}

	return true;
}


int main()
{
	int Matrix1[3][3] =
	{
		{9, 0, 0},
		{0, 9, 0},
		{0, 0, 9}
	};

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsScalarMatrix(Matrix1, 3, 3))
		cout << "\nYES: Matrix is scalar.\n";
	else
		cout << "\nNO: Matrix is NOT scalar.\n";


	return 0;
}