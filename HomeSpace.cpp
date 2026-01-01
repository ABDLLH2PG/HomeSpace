#include <iostream>
using namespace std;

//Function Overloading

int MySum(int Num1, int Num2)
{
	return (Num1 + Num2);
}

double MySum(double num1, double num2)
{
	return (num1 + num2);
}

int MySum(int Num1, int Num2, int Num3)
{
	return (Num1 + Num2 + Num3);
}

int MySum(int Num1, int Num2, int Num3, int Num4)
{
	return (Num1 + Num2 + Num3 + Num4);
}


int main()
{
	cout << MySum(10, 20) << endl;
	cout << MySum(10.5, 20.5) << endl;
	cout << MySum(10, 20, 30) << endl;
	cout << MySum(10, 20, 30, 40) << endl;


	return 0;
}
