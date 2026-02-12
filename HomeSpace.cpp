#include <iostream>
#include <string>
#include <iomanip>
#include "MyInputLib.h";

using namespace std;

// [C07] Problem #21: Fibonacci Series [Optimized Code]
void PrintFibonacciUsingLoop(int Lentgh)
{
	int FebNumber = 0, Prev1 = 1, Prev2 = 0;
	cout << setw(3) << Prev1 << "   ";

	for (short i = 1; i < Lentgh; i++)
	{
		FebNumber = Prev1 + Prev2;

		cout << setw(3) << FebNumber << "   ";

		Prev2 = Prev1;
		Prev1 = FebNumber;
	}
}


int main()
{
	int Number = MyInputLib::ReadNumber("Please enter Number ? ");

	cout << "\n";

	PrintFibonacciUsingLoop(Number);

	system("pause>0");

	return 0;
}