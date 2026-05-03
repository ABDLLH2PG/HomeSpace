#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #03: Leap Year (One Line Of Code) [My Solution]

bool IsLeapYear(short Year)
{
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