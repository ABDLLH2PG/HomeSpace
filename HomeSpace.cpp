#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// [C07] Problem #15: Count Number in Matrix [Optimized Code]
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

	int Number;
	cout << "\nEnter the number to count in matrix? ";
	cin >> Number;

	cout << "\nNumber " << Number << " count in matrix is " << CountNumberInMatrix(Matrix1, Number, 3, 3) << endl;


	return 0;
}