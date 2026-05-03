#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #02: Leap Year [Optimized Code]

bool IsLeapYear(short Year)
{
	// leap year if perfectly divisible by 400
	if (Year % 400 == 0)
	{
		return true;
	}

	// not a leap year if divisible by 100
	// but not divisible by 400
	else if (Year % 100 == 0)
	{
		return false;
	}

	// leap year if not divisible by 100
	// but divisible by 4
	else if (Year % 4 == 0)
	{
		return true;
	}

	// all other years are not leap years
	else
	{
		return false;
	}
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