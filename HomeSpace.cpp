#include <iostream>
#include <string>
#include <iomanip>
#include "MyUtilityLib.h"

using namespace std;

// [C07] Problem #13: Check Identity Matrix [Optimized Code]
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

bool IsIdentityMatrices(int Matrix[3][3], short Rows, short Cols)
{
	//check Diagonal elements are 1 and rest elements are 0

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			//check for diagonals element
			if (i == j && Matrix[i][j] != 1)
			{
				return false;
			}
			//check for rest elements
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
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}
	};

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsIdentityMatrices(Matrix1, 3, 3))
		cout << "\nYES: Matrix is identity.\n";
	else
		cout << "\nNO: Matrix is NOT identity.\n";


	return 0;
}