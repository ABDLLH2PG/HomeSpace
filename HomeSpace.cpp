#include <iostream>
#include <string>
#include <iomanip>
#include "MyInputLib.h";

using namespace std;

// [C07] Problem #21: Fibonacci Series [My Solution]
void PrintFibonacciSeries(int Lentgh)
{
	int Number ,Prev1 = 1, Prev2 = 1;

	cout << setw(3) << Prev1 << "   ";
	cout << setw(3) << Prev2 << "   ";

	for (short i = 0; i < Lentgh - 2; i++)
	{
		Number = Prev1 + Prev2;

		cout << setw(3) << Number << "   ";

		Prev2 = Prev1;
		Prev1 = Number;
	}
}


int main()
{
	int Number = MyInputLib::ReadNumber("Please enter Number ? ");

	cout << "\n";

	PrintFibonacciSeries(Number);

	system("pause>0");

	return 0;
}