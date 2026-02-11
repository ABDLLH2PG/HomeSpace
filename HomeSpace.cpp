#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// [C07] Problem #16: Check Sparse Matrix [My Solution]
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

bool SparceMatric(int Matrix1[3][3], short Rows, short Cols)
{
	short Counter = 0;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == 0)
			{
				Counter++;
			}
		}
	}

	if (Counter > ((Rows * Cols) / 2) )
		return true;
	else
		return false;
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

	if (SparceMatric(Matrix1, 3, 3))
	{
		cout << "\nYes: It is Sparse\n";
	}
	else
	{
		cout << "\nNo: It's Not Sparce\n";
	}


	return 0;
}