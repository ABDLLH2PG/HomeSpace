#include <iostream>
#include <string>
#include <iomanip>
#include "MyUtilityLib.h"

using namespace std;

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

bool AreIdentityMatrices(int Matrix[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == 1)
			{
				if (Matrix[i][j + 1] == 0)
				{
					// I Can not think what I can do!!
				}
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

	if (AreIdentityMatrices(Matrix1, 3, 3))
		cout << "\nYES: Matrix is identity.\n";
	else
		cout << "\nNO: Matrix is NOT identity.\n";


	return 0;
}