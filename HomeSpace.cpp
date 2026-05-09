#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #12: Add Days to Date [My Solution]

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

sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{
	sDate Date;
	short RemainingDays = DateOrderInYear;
	short MonthDays = 0;

	Date.Year = Year;
	Date.Month = 1;

	while (true)
	{
		MonthDays = NumberOfDaysInAMonth(Year, Date.Month);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}

	return Date;
}

sDate AddDaysToDate(sDate Date, short DaysAdd)
{
	short RemainingDays = NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year) + DaysAdd;
	short DaysInYear = 0;

	while (true)
	{
		DaysInYear = IsLeapYear(Date.Year) ? 366 : 365;

		if (RemainingDays > DaysInYear)
		{
			RemainingDays -= DaysInYear;
			Date.Year++;
		}
		else
		{
			Date = GetDateFromDayOrderInYear(RemainingDays, Date.Year);
			return Date;
		}
	}
}


int main()
{
	short Day = MyInputLib::ReadNumber("\nPlease enter a Day? ");
	short Month = MyInputLib::ReadNumber("\nPlease enter a Month? ");
	short Year = MyInputLib::ReadNumber("\nPlease enter a Year? ");
	short DaysAdd = MyInputLib::ReadNumber("\nHow many days to add? ");

	short DaysOrderInYear = NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);

	sDate Date;
	Date = GetDateFromDayOrderInYear(DaysOrderInYear, Year);
	Date = AddDaysToDate(Date, DaysAdd);

	cout << "\nDate after adding [" << DaysAdd << "] days is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");

	return 0;
}