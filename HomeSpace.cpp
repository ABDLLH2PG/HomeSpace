#include <iostream>
#include <string>
#include <iomanip>
#include "MyUtilityLib.h"

using namespace std;

// [C07] Problem #10: Sum of Matrix [Optimized Code]
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr[i][j] = MyUtilityLib::RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf(" %0*d    ", 2, arr[i][j]);
		}

		cout << "\n";
	}
}

int SumOfMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	int Sum = 0;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Sum += Matrix1[i][j];
		}
	}

	return Sum;
}


int main()
{
	MyUtilityLib::SeedRand();

	int Matrix1[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nSum of Matrix1 is: " << SumOfMatrix(Matrix1, 3, 3) << endl;

	system("pause>0");

	return 0;
}