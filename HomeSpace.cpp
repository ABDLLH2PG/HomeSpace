#include <iostream>
#include <string>
#include <iomanip>
#include "MyInputLib.h";

using namespace std;

// [C07] Problem #22: Fibonacci Series With Recursion [Optimized Code]
void PrintFibonacciUsingRecursion(short Number, int Prev1, int Prev2)
{
	int FebNumber = 0;

	if (Number > 0)
	{
		FebNumber = Prev2 + Prev1;

		Prev2 = Prev1;
		Prev1 = FebNumber;

		cout << FebNumber << "    ";

		PrintFibonacciUsingRecursion(Number - 1, Prev1, Prev2);
	}
}


int main()
{
	int Number = MyInputLib::ReadNumber("Please enter Number ? ");

	cout << "\n";

	PrintFibonacciUsingRecursion(Number, 0, 1);

	system("pause>0");

	return 0;
}