#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// [C07] Problem #17: Number Exists In Matrix [My Solution]
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

short CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
	short NumberCount = 0;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == Number)
			{
				NumberCount++;
			}
		}
	}

	return NumberCount;
}

bool IsExistsInMatrix(int Matrix1[3][3], short Number, short Rows, short Cols)
{
	return (CountNumberInMatrix(Matrix1, Number, Rows, Cols) > 0);
}


int main()
{
	int Matrix1[3][3] =
	{
		{77, 5, 12},
		{22, 20, 1},
		{1, 0, 9}
	};

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	int Number;

	cout << "\nPlease Enter the number to look for in matrix? ";
	cin >> Number;


	if (IsExistsInMatrix(Matrix1, Number, 3, 3))
	{
		cout << "\nYes: It is there\n";
	}
	else
	{
		cout << "\nNo: It's Not there\n";
	}

	system("pause>0");

	return 0;
}