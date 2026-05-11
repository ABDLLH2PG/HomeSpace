#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #13: Date 1 Less Than Date 2 [My Solution]

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

struct sDate
{
	short Year;
	short Month;
	short Day;
};

sDate ReadFullDate()
{
	sDate Date;

	Date.Day = MyInputLib::ReadNumber("\nPlease enter a Day? ");
	Date.Month = MyInputLib::ReadNumber("Please enter a Month? ");
	Date.Year = MyInputLib::ReadNumber("Please enter a Year? ");

	return Date;
}

bool Date1LessThanDate2(sDate Date1, sDate Date2)
{
	return Date1.Year < Date2.Year ? true
		: Date1.Month < Date2.Month ? true
		: Date1.Day < Date2.Day ? true : false;
}


int main()
{
	sDate Date1 = ReadFullDate();
	sDate Date2 = ReadFullDate();

	if (Date1LessThanDate2(Date1, Date2))
	{
		cout << "\nYes, Date1 is Less than Date2.";
	}
	else
	{
		cout << "\nNo, Date1 is Not Less than Date2.";
	}


	system("pause>0");

	return 0;
}