#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #54: Calculate Vacation Days [Optimized Code]

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

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
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

short DayOfWeekOrder(short Year, short Month, short Day)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stDate Date)
{
	return DayOfWeekOrder(Date.Year, Date.Month, Date.Day);
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	return arrDayNames[DayOfWeekOrder];
}

bool IsEndOfWeek(stDate Date)
{
	return DayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd(stDate Date)
{
	//Weekends are Fri and Sat
	short DayIndex = DayOfWeekOrder(Date);
	return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(stDate Date)
{
	return !IsWeekEnd(Date);
}

short CalculateVacationDays(stDate DateFrom, stDate DateTo)
{
	short DaysCount = 0;

	while (IsDate1BeforeDate2(DateFrom, DateTo))
	{
		if (IsBusinessDay(DateFrom))
			DaysCount++;

		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	return DaysCount;
}


int main()
{
	cout << "\nVacation Starts:";
	stDate DateFrom = ReadFullDate();
	
	cout << "\nVacation Ends:";
	stDate DateTo = ReadFullDate();

	cout << "\nVaction From: " << DayShortName(DayOfWeekOrder(DateFrom)) << " , "; PrintDate(DateFrom);
	cout << "\nVaction To: " << DayShortName(DayOfWeekOrder(DateTo)) << " , "; PrintDate(DateTo);

	cout << "\n\n\nActucal Vacation Days is: " << CalculateVacationDays(DateFrom, DateTo);


	system("pause>0");

	return 0;
}