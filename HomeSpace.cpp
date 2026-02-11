#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// [C07] Problem #16: Check Sparse Matrix [Optimized Code]
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

bool IsSparseMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	short MatrixSize = Rows * Cols;

	return (CountNumberInMatrix(Matrix1, 0, 3, 3) >= (MatrixSize / 2));
}


int main()
{
	int Matrix1[3][3] =
	{
		{0, 0, 12},
		{0, 0, 1},
		{0, 0, 9}
	};

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsSparseMatrix(Matrix1, 3, 3))
	{
		cout << "\nYes: It is Sparse\n";
	}
	else
	{
		cout << "\nNo: It's Not Sparse\n";
	}

	system("pause>0");

	return 0;
}