#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #47-53: More Date Problems [My Solution]

struct stDate
{
	short Year;
	short Month;
	short Day;
};

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

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
	short TotalDays = 0;

	for (short i = 1; i <= Month - 1; i++)
	{
		TotalDays += NumberOfDaysInAMonth(Year, i);
	}

	return (TotalDays + Day);
}

void PrintDate(stDate Date)
{
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
}

stDate GetSystemDate()
{
	stDate Date;

	time_t t = time(0);
	tm* now = localtime(&t);

	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;

	return Date;
}

stDate DrDate()
{
	stDate Date;

	Date.Day = 23, Date.Month = 9, Date.Year = 2022;

	return Date;
}

short DayOfWeekOrder(stDate Date)
{
	short a, y, m;
	a = (14 - Date.Month) / 12;
	y = Date.Year - a;
	m = Date.Month + (12 * a) - 2;

	return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	return arrDayNames[DayOfWeekOrder];
}

bool IsEndOfWeek(short DayOrder)
{
	return (DayOrder == 6) ? true : false;
}

bool IsWeekEnd(short DayOrder)
{
	return (DayOrder == 5 || DayOrder == 6) ? true : false;
}

bool IsBusinessDay(short DayOrder)
{
	return (!IsWeekEnd(DayOrder)) ? true : false;
}

short DaysUntiTheEndOfWeek(stDate Date)
{
	return 6 - DayOfWeekOrder(Date);
}

short DaysUntiTheEndOfMonth(stDate Date)
{
	short DaysInMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

	return (DaysInMonth - Date.Day) + 1;
}

short DaysUntiTheEndOfYear(stDate Date)
{
	short DaysInYear = (IsLeapYear(Date.Year) ? 366 : 365);

	short DaysFromBeginningofYear = NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);

	return (DaysInYear - DaysFromBeginningofYear) + 1;
}


int main()
{
	//stDate Date = GetSystemDate();
	stDate Date = DrDate();

	short DayOrder = DayOfWeekOrder(Date);

	cout << "\nToday is " << DayShortName(DayOrder) << " , "; PrintDate(Date);

	cout << "\n\nIs it End of Week?";
	if (IsEndOfWeek(DayOrder))
		cout << "\nYes end of week.";
	else
		cout << "\nNo Not end of week.";

	cout << "\n\nIs it Weekend?";
	if (IsWeekEnd(DayOrder))
		cout << "\nYes it is a week end.";
	else
		cout << "\nNo it is Not a week end.";

	cout << "\n\nIs it Business Day?";
	if (IsBusinessDay(DayOrder))
		cout << "\nYes it is a business day.";
	else
		cout << "\nNo it is NOT a business day.";

	cout << "\n\nDays until end of week : " << DaysUntiTheEndOfWeek(Date) << " Days(s).";
	cout << "\nDays until end of month : " << DaysUntiTheEndOfMonth(Date) << " Days(s).";
	cout << "\nDays until end of year : " << DaysUntiTheEndOfYear(Date) << " Days(s).";


	system("pause>0");

	return 0;
}