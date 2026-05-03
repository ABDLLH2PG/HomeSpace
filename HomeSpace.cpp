#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #04: Number of Days-Hours-Minutes-Seconds In a Year [Optimized Code]

bool IsLeapYear(short Year)
{
	// if year is divisible by 4 AND bot divisible by 100
	// OR if year is divisible by 400
	// them it is a leap year

	return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
}

short NumberOfDaysInAYear(short Year)
{
	return IsLeapYear(Year) ? 366 : 365;
}

short NumberOfHoursInAYear(short Year)
{
	return NumberOfDaysInAYear(Year) * 24;
}

int NumberOfMinutesInAYear(short Year)
{
	return NumberOfHoursInAYear(Year) * 60;
}

int NumberOfSecondsInAYear(short Year)
{
	return NumberOfMinutesInAYear(Year) * 60;
}


int main()
{
	short Year = MyInputLib::ReadNumber("\nPlease enter a year to check? ");

	cout << "\nNumber of Days    in Year [" << Year << "] is " << NumberOfDaysInAYear(Year);
	cout << "\nNumber of Hours   in Year [" << Year << "] is " << NumberOfHoursInAYear(Year);
	cout << "\nNumber of Minutes in Year [" << Year << "] is " << NumberOfMinutesInAYear(Year);
	cout << "\nNumber of Seconds in Year [" << Year << "] is " << NumberOfSecondsInAYear(Year);


	system("pause>0");

	return 0;
}