#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #09: Year Calendar [Optimized Code]

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

short DayOfWeekOrder(short Year, short Month, short Day)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string MonthShortName(short MonthNumber)
{
	string Months[12] = { "Jan", "Feb", "Mar",
						  "Apr", "May", "Jun",
						  "Jul", "Aug", "Sep",
						  "Oct", "Nov", "Dec" };

	return (Months[MonthNumber - 1]);
}

void PrintMonthCalendar(short Year, short Month)
{
	// Index of the day from 0 to 6
	int current = DayOfWeekOrder(Year, Month, 1);

	int NumberOfDays = NumberOfDaysInAMonth(Year, Month);

	// Print the current month name
	printf("\n  _______________%s_______________\n\n",
		MonthShortName(Month).c_str());

	// Print the columns
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
	
	// Print appropriate spaces
	int i;
	for (i = 0; i < current; i++)
	{
		printf("     ");
	}

	for (int j = 1; j <= NumberOfDays; j++)
	{
		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}

	printf("\n  _________________________________\n");
}

void PrintYearCalendar(short Year)
{
	printf("\n  _________________________________\n");
	printf("\n         Calendar - %d", Year);
	printf("\n  _________________________________\n");

	for (short i = 1; i <= 12; i++)
	{
		PrintMonthCalendar(Year, i);
	}
}


int main()
{
	short Year = MyInputLib::ReadNumber("\nPlease enter a year? ");

	PrintYearCalendar(Year);


	system("pause>0");

	return 0;
}