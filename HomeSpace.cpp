#include <iostream>
#include <string>
#include <iomanip>
#include "MyUtilityLib.h"

using namespace std;

// [C07] Problem #15: Count Number in Matrix [My Solution]
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

int ReadNumber()
{
	int Number = 0;

	cout << "\nEnter the number to count in matrix? ";
	cin >> Number;

	return Number;
}

void CheckNumberInMatrix(int Matrix1[3][3], short Rows, short Cols, int Number)
{
	int Counter = 0;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == Number)
			{
				Counter++;
			}
		}
	}

	cout << "\nNumber " << Number << " count in matrix is " << Counter << endl;
}


int main()
{
	int Matrix1[3][3] =
	{
		{9, 1, 12},
		{0, 9, 1},
		{0, 9, 9}
	};

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	int Number = ReadNumber();

	CheckNumberInMatrix(Matrix1, 3, 3, Number);


	return 0;
}