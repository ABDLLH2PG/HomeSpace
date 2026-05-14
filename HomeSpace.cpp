#include <iostream>
#include <string>
#include <ctime>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #18: Your Age In Days [My Solution]

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

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
	short TotalDays = 0;

	for (short i = 1; i <= Month - 1; i++)
	{
		TotalDays += NumberOfDaysInAMonth(Year, i);
	}

	return (TotalDays + Day);
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

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;

	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}

	return IncludeEndDay ? ++Days : Days;
}

int GetYourDateOfBirth(stDate Date)
{
	time_t t = time(0);



}


int main()
{
	cout << "\nPlease Enter Your Date of Birth:\n";
	stDate Date = ReadFullDate();

	cout << "\nYour Age is : " << GetYourDateOfBirth(Date) << " Day(s).";


	system("pause>0");

	return 0;
}