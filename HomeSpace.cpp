#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #06: Number of Days In a Month Short Logic [Optimized Code]

bool IsLeapYear(short Year)
{
	// if year is divisible by 4 AND bot divisible by 100
	// OR if year is divisible by 400
	// them it is a leap year

	return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
}

short NumberOfDaysInAMonth(short Year, short Month)
{
	if (Month < 1 || Month > 12)
		return 0;

	int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return (Month == 2) ? IsLeapYear(Year) ? 29 : 28 : NumberOfDays[Month - 1];
}

short NumberOfHoursInAMonth(short Year, short Month)
{
	return NumberOfDaysInAMonth(Year, Month) * 24;
}

int NumberOfMinutesInAMonth(short Year, short Month)
{
	return NumberOfHoursInAMonth(Year, Month) * 60;
}

int NumberOfSecondsInAMonth(short Year, short Month)
{
	return NumberOfMinutesInAMonth(Year, Month) * 60;
}


int main()
{
	short Year = MyInputLib::ReadNumber("\nPlease enter a year to check? ");

	short Month = MyInputLib::ReadNumber("\nPlease enter a Month to check? ");

	cout << "\nNumber of Days    in Month [" << Month << "] is " << NumberOfDaysInAMonth(Year, Month);
	cout << "\nNumber of Hours   in Month [" << Month << "] is " << NumberOfHoursInAMonth(Year, Month);
	cout << "\nNumber of Minutes in Month [" << Month << "] is " << NumberOfMinutesInAMonth(Year, Month);
	cout << "\nNumber of Seconds in Month [" << Month << "] is " << NumberOfSecondsInAMonth(Year, Month);


	system("pause>0");

	return 0;
}