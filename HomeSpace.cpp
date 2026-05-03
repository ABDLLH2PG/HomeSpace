#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #04: Number of Days-Hours-Minutes-Seconds In a Year [My Solution]

bool IsLeapYear(short Year)
{
	// if year is divisible by 4 AND bot divisible by 100
	// OR if year is divisible by 400
	// them it is a leap year

	return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
}

int NumberOfDaysInYear(short Year)
{
	return IsLeapYear(Year) ? 366 : 365;
}

int NumberOfHoursInYear(short Year)
{
	return NumberOfDaysInYear(Year) * 24;
}

int NumberOfMinutesInYear(short Year)
{
	return NumberOfHoursInYear(Year) * 60;
}

int NumberOfSecondsInYear(short Year)
{
	return NumberOfMinutesInYear(Year) * 60;
}


int main()
{
	short Year = MyInputLib::ReadNumber("\nPlease enter a year to check? ");

	cout << "\nNumber of Days    in Year [" << Year << "] is " << NumberOfDaysInYear(Year);
	cout << "\nNumber of Hours   in Year [" << Year << "] is " << NumberOfHoursInYear(Year);
	cout << "\nNumber of Minutes in Year [" << Year << "] is " << NumberOfMinutesInYear(Year);
	cout << "\nNumber of Seconds in Year [" << Year << "] is " << NumberOfSecondsInYear(Year);


	system("pause>0");

	return 0;
}