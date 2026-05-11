#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #15: Last Day, Last Month [My Solution]

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

bool IsLastMonthInYear(stDate Date)
{
	return (Date.Month == 12);
}


int main()
{
	stDate Date = ReadFullDate();

	if (IsLastDayInMonth(Date))
		cout << "\nYes, Day is Last Day in Month.";
	else
		cout << "\nNo, Day is NOT Last Day in Month.";

	if (IsLastMonthInYear(Date))
		cout << "\nYes, Month is Last Month in Year.";
	else
		cout << "\nNo, Month is NOT Last Month in Year.";


	system("pause>0");

	return 0;
}