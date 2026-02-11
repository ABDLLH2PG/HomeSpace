#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// [C07] Problem #18: Intersected Numbers in Matrices [My Solution]
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

bool IsNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == Number)
			{
				return true;
			}
		}
	}
	return false;

}

void PrintIntersectedNumberInTwoMatrix(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	int arr3[10];
	short Num = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (IsNumberInMatrix(Matrix2, Matrix1[i][j], 3, 3))
			{
				arr3[Num] = Matrix1[i][j];
				Num++;
			}
		}
	}

	cout << "\nIntersected Numbers are:\n\n";
	for (short k = 0; k < Num; k++)
	{
		cout << left << setw(3) << arr3[k] << "    ";
	}
}


int main()
{
	int Matrix1[3][3] =
	{
		{77,  5, 12},
		{22, 20,  1},
		{1 ,  0,  9}
	};

	int Matrix2[3][3] =
	{
		{5 , 80, 90},
		{22, 77,  1},
		{10,  8, 33}
	};

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	PrintIntersectedNumberInTwoMatrix(Matrix1, Matrix2, 3, 3);

	system("pause>0");

	return 0;
}