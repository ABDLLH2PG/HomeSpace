#include <iostream>
#include <string>
#include <iomanip>
#include "MyInputLib.h";

using namespace std;

// [C07] Problem #22: Fibonacci Series With Recursion [My Solution]
void PrintFibonacciUsingRecursion(int Length,int N = 1, int Prev1 = 1, int Prev2 = 0)
{
	if (N < Length)
	{
		if (N == 1)
			cout << setw(3) << Prev1 << "   ";

		int FebNumber = Prev1 + Prev2;

		cout << setw(3) << FebNumber << "   ";


		Prev2 = Prev1;
		Prev1 = FebNumber;

		PrintFibonacciUsingRecursion(Length, N + 1, Prev1, Prev2);
	}
}


int main()
{
	int Number = MyInputLib::ReadNumber("Please enter Number ? ");

	cout << "\n";

	PrintFibonacciUsingRecursion(Number);

	system("pause>0");

	return 0;
}