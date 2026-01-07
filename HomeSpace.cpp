#include <iostream>
using namespace std;

//Lesson #27 - Two Dimensional Arrays [HomeWork Solution]
void StoreMultiplicationTable(int Table[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Table[i][j] = ((i + 1) * (j + 1));
		}
	}
}

void PrintMultiplicationTable(int Table[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%0*d ", 2, Table[i][j]);
		}

		cout << endl;
	}
}

int main()
{
	// int Table[Rows][Cols];
	int Table[10][10];

	StoreMultiplicationTable(Table);

	PrintMultiplicationTable(Table);


	return 0;
}