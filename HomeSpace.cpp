#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// [C07] Problem #07: Traspose Matrix[My Solution]
void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols)
{
	short Counter = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Counter++;
			arr[i][j] = Counter;
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		}

		cout << endl;
	}
}

void TransposeMatrix(int arr[3][3], int TransMatrix[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			TransMatrix[j][i] = arr[i][j];
		}
	}
}

int main()
{
	int arr[3][3];

	FillMatrixWithOrderedNumbers(arr, 3, 3);

	cout << "\nThe following is a 3x3 ordered matrix:\n";
	PrintMatrix(arr, 3, 3);

	int TransMatrix[3][3];

	TransposeMatrix(arr, TransMatrix, 3, 3);

	cout << "\nThe following is the transposed matrix:\n";
	PrintMatrix(TransMatrix, 3, 3);
	



	return 0;
}