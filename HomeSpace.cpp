#include <iostream>
using namespace std;

//Lesson #19 - Recursion (HomeWork-2)

//My Solution:
int CalculatePowerOfM(int N, int M)
{
	int Sum = 1;

	if (M != 0)
	{
		Sum *= N;
		Sum *= CalculatePowerOfM(N, M - 1);
	}

	return Sum;
}

//Doctor Solution:
int MyPower(int Base, int Power)
{
	if (Power == 0)
		return 1;
	else
	{
		return (Base * MyPower(Base, Power - 1));
	}
}

int main()
{
	cout << CalculatePowerOfM(2, 4) << endl;
	cout << MyPower(2, 4) << endl;

	return 0;
}