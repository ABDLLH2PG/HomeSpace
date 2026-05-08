#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #11: Date from Day Order In a year [My Solution]

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

	if (Month == 2)
	{
		return IsLeapYear(Year) ? 29 : 28;
	}

	short arr31Days[7] = { 1, 3, 5, 7, 8, 10, 12 };

	for (short i = 1; i <= 7; i++)
	{
		if (arr31Days[i - 1] == Month)
			return 31;
	}

	// if you reach here then its 30 days.
	return 30;
}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
	short TotalDays = 0;

	for (short i = 1; i <= Month - 1; i++)
	{
		TotalDays += NumberOfDaysInAMonth(Year, i);
	}

	return (TotalDays + Day);
}

void DateFromDayOrderInAYear(short TotalDays, short Year)
{
	short DaysOfMonth = 0;

	for (short i = 1; i <= 12; i++)
	{
		DaysOfMonth = NumberOfDaysInAMonth(Year, i);

		if (TotalDays >= DaysOfMonth)
		{
			TotalDays -= DaysOfMonth;
		}
		else
		{
			cout << TotalDays << "/" << i << "/" << Year;
			break;
		}
	}
}


int main()
{
	short Day = MyInputLib::ReadNumber("\nPlease enter a Day? ");
	short Month = MyInputLib::ReadNumber("\nPlease enter a Month? ");
	short Year = MyInputLib::ReadNumber("\nPlease enter a Year? ");

	short NumberOfDays = NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);

	cout << "\nNumber of Days from the begining of the year is "
		<< NumberOfDays;

	cout << "\n\nDate for [" << NumberOfDays << "] is: ";
	DateFromDayOrderInAYear(NumberOfDays, Year);

	system("pause>0");

	return 0;
}