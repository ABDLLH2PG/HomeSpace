#include <iostream>
#include "MyUtilityLib.h"
using namespace std;

// [C07] Problem #01: 3x3 Random Matrix (My Solution)
void Fill2DArrayWithRandomNumber(int arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = MyUtilityLib::RandomNumber(1, 100);
		}
	}
}

void Print2DArrayWithRandomNumber(int arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << "\t";
		}

		cout << endl;
	}
}


int main()
{
	MyUtilityLib::SeedRand();

	int arr[3][3];
	cout << "The following is a 3x3 random matrix:" << endl;

	Fill2DArrayWithRandomNumber(arr);

	Print2DArrayWithRandomNumber(arr);
	

	return 0;
}