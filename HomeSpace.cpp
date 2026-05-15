#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #20-32: Increase Date Problems [My Solution]

struct stDate
{
	short Year;
	short Month;
	short Day;
};

stDate ReadFullDate()
{
	stDate Date;

	Date.Day = MyInputLib::ReadNumber("\nPlease enter a Day? ");
	Date.Month = MyInputLib::ReadNumber("Please enter a Month? ");
	Date.Year = MyInputLib::ReadNumber("Please enter a Year? ");

	return Date;
}

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

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

void PrintDate(stDate Date)
{
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
}

stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}

	return Date;
}

stDate IncreaseDateByXDays(stDate Date, int Days)
{
	for (int i = 0; i < Days; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}

	return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
	return Date = IncreaseDateByXDays(Date, 7);
}

stDate IncreaseDateByXWeeks(stDate Date, int Weeks)
{
	for (int i = 0; i < Weeks; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}

	return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
	short DaysInCurrentMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

	return Date = IncreaseDateByXDays(Date, DaysInCurrentMonth);
}

stDate IncreaseDateByXMonth(stDate Date, int Months)
{
	for (int i = 0; i < Months; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}

	return Date;
}


int main()
{
	stDate Date = ReadFullDate();
	cout << "\nDate After:\n";

	Date = IncreaseDateByOneDay(Date);
	cout << "\n01-Adding one day is: ";
	PrintDate(Date);

	Date = IncreaseDateByXDays(Date, 10);
	cout << "\n02-Adding 10 days is: ";
	PrintDate(Date);

	Date = IncreaseDateByOneWeek(Date);
	cout << "\n03-Adding one week is: ";
	PrintDate(Date);

	Date = IncreaseDateByXWeeks(Date, 10);
	cout << "\n04-Adding 10 weeks is: ";
	PrintDate(Date);

	Date = IncreaseDateByOneMonth(Date);
	cout << "\n05-Adding one month is: ";
	PrintDate(Date);

	Date = IncreaseDateByXMonth(Date, 5);
	cout << "\n06-Adding 5 months is: ";
	PrintDate(Date);



	system("pause>0");

	return 0;
}