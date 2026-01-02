#include <iostream>
using namespace std;

//Lesson #19 - Recursion (HomeWork-1)

//My Solution:
void PrintNumbers(int M, int N)
{
	if (M >= N)
	{
		cout << M << endl;
		PrintNumbers(M - 1, N);
	}
}

//Doctor Solution:
void PrintNumbersFromMToN(int M, int N)
{
	if (M >= N)
	{
		cout << M << endl;
		PrintNumbersFromMToN(M - 1, N);
	}
}

int main()
{
	PrintNumbers(10, 1);
	PrintNumbersFromMToN(10, 1);

	return 0;
}
