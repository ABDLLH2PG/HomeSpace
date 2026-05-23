#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #58: Is Overlap Periods [My Solution]

struct stDate
{
	short Year;
	short Month;
	short Day;
};

struct stPeriod
{
	stDate Start;
	stDate End;
};

stDate ReadFullDate()
{
	stDate Date;

	Date.Day = MyInputLib::ReadNumber("\nPlease enter a Day? ");
	Date.Month = MyInputLib::ReadNumber("Please enter a Month? ");
	Date.Year = MyInputLib::ReadNumber("Please enter a Year? ");

	return Date;
}

void PrintDate(stDate Date)
{
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year)
		? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month
			? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year)
		? ((Date1.Month == Date2.Month)
			? ((Date1.Day == Date2.Day)
				? true : false) : false) : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2)) && (!IsDate1EqualDate2(Date1, Date2));
}

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareDate(stDate Date1, stDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;

	if (IsDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;

	return enDateCompare::After;
}

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
	return (IsDate1BeforeDate2(Period2.Start, Period1.End) && IsDate1BeforeDate2(Period1.Start, Period2.End));
}


int main()
{
	cout << "\nEnter Period 1:";
	stPeriod Period1;
	cout << "\nEnter Start Date:\n";
	Period1.Start = ReadFullDate();
	cout << "\nEnter End Date:\n";
	Period1.End = ReadFullDate();

	cout << "\nEnter Period 2:";
	stPeriod Period2;
	cout << "\nEnter Start Date:\n";
	Period2.Start = ReadFullDate();
	cout << "\nEnter End Date:\n";
	Period2.End = ReadFullDate();

	if (IsOverlapPeriods(Period1, Period2))
	{
		cout << "\nYes, Periods Overlap";
	}
	else
	{
		cout << "\nNo, Periods Not Overlap";
	}

	system("pause>0");

	return 0;
}