#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// [C07] Problem #06: 3x3 Ordered Matrix [My Solution]
void FillArrayWithOrderedNumbers(int arr[3][3])
{
	int Counter = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = ++Counter;
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


int main()
{
	int arr[3][3];

	FillArrayWithOrderedNumbers(arr);

	cout << "\nThe following is a 3x3 ordered matrix:\n";
	PrintMatrix(arr, 3, 3);

	system("pause>0");

	return 0;
}