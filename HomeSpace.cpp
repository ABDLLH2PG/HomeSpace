#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #03: Leap Year (One Line Of Code) [Optimized Code]

bool IsLeapYear(short Year)
{
	// if year is divisible by 4 AND bot divisible by 100
	// OR if year is divisible by 400
	// them it is a leap year

	return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
}


int main()
{
	short Year = MyInputLib::ReadNumber("\nPlease enter a year to check? ");

	if (IsLeapYear(Year))
	{
		cout << "\nYes, Year [" << Year << "] is a leap year.\n";
	}
	else
	{
		cout << "\nNo, Year [" << Year << "] is NOT a leap year.\n";
	}

	system("pause>0");

	return 0;
}