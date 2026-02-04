#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// [C07] Problem #07: Traspose Matrix [Optimized Code]
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

void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arrTransposed[i][j] = arr[j][i];
		}
	}
}


int main()
{
	int arr[3][3];

	FillMatrixWithOrderedNumbers(arr, 3, 3);

	cout << "\nThe following is a 3x3 ordered matrix:\n";
	PrintMatrix(arr, 3, 3);

	int arrTransposed[3][3];

	TransposeMatrix(arr, arrTransposed, 3, 3);

	cout << "\nThe following is the transposed matrix:\n";
	PrintMatrix(arrTransposed, 3, 3);
	
	system("pause>0");


	return 0;
}