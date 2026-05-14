#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #17: Diff In Days [My Solution]

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

short DiffDaysInTwoDate(stDate Date1, stDate Date2, bool EndDay = false)
{
	short TotalDays = 0;

	if (Date1.Year != Date2.Year)
	{
		short NumberOfDiffYear = Date2.Year - Date1.Year;

		for (short i = 0; i < NumberOfDiffYear; i++)
		{
			TotalDays += (IsLeapYear(Date1.Year + i) ? 366 : 365);
		}
	}

	short Date1Days = NumberOfDaysFromTheBeginingOfTheYear(Date1.Day, Date1.Month, Date1.Year);
	short Date2Days = NumberOfDaysFromTheBeginingOfTheYear(Date2.Day, Date2.Month, Date2.Year);

	TotalDays += Date2Days - Date1Days;

	return TotalDays += (EndDay ? 1 : 0);
}


int main()
{
	stDate Date1 = ReadFullDate();
	stDate Date2 = ReadFullDate();

	cout << "\nDiffrence is: " << DiffDaysInTwoDate(Date1, Date2) << " Days(s).";
	cout << "\nDiffrence (Including End Day) is: " << DiffDaysInTwoDate(Date1, Date2, true) << " Days(s).";

	system("pause>0");

	return 0;
}