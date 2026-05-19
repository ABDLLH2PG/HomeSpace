#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #33-46: Decrease Date Problems [My Solution]

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

stDate DecreaseDateByOneDay(stDate Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Day = NumberOfDaysInAMonth(Date.Year - 1, 12);
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Day = NumberOfDaysInAMonth(Date.Year, Date.Month - 1);
			Date.Month--;
		}
	}
	else
	{
		Date.Day--;
	}

	return Date;
}

stDate DecreaseDateByXDay(short Days, stDate Date)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}

	return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
	for (short i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}

	return Date;
}

stDate DecreaseDateByXWeeks(short Weeks, stDate Date)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}

	return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}

	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

stDate DecreaseDateByXMonth(short Months, stDate Date)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}

	return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
	return DecreaseDateByXMonth(12, Date);
}

stDate DecreaseDateByXYear(short Years, stDate Date)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}

	return Date;
}

stDate DecreaseDateByXYearFaster(short Years, stDate Date)
{
	Date.Year -= Years;
	return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{
	for (short i = 1; i <= 10; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}

	return Date;
}

stDate DecreaseDateByXDecade(short Decades, stDate Date)
{
	for (short i = 1; i <= Decades * 10; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}

	return Date;
}

stDate DecreaseDateByXDecadeFaster(short Decades, stDate Date)
{
	Date.Year -= Decades * 10;
	return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
	Date.Year -= 100;
	return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
	Date.Year -= 1000;
	return Date;
}


int main()
{
	stDate Date = ReadFullDate();
	cout << "\nDate After:\n";

	Date = DecreaseDateByOneDay(Date);
	cout << "\n01-Subtracting one day is: ";
	PrintDate(Date);

	Date = DecreaseDateByXDay(10, Date);
	cout << "\n02-Subtraction 10 days is: ";
	PrintDate(Date);
	
	Date = DecreaseDateByOneWeek(Date);
	cout << "\n03-Subtraction one week is: ";
	PrintDate(Date);

	Date = DecreaseDateByXWeeks(10, Date);
	cout << "\n04-Subtraction 10 weeks is: ";
	PrintDate(Date);

	Date = DecreaseDateByOneMonth(Date);
	cout << "\n05-Subtraction one month is: ";
	PrintDate(Date);

	Date = DecreaseDateByXMonth(5, Date);
	cout << "\n06-Subtraction 5 months is: ";
	PrintDate(Date);

	Date = DecreaseDateByOneYear(Date);
	cout << "\n07-Subtraction one year is: ";
	PrintDate(Date);

	Date = DecreaseDateByXYear(10, Date);
	cout << "\n08-Subtraction 10 Years is: ";
	PrintDate(Date);

	Date = DecreaseDateByXYearFaster(10, Date);
	cout << "\n09-Subtraction 10 Years (faster) is: ";
	PrintDate(Date);

	Date = DecreaseDateByOneDecade(Date);
	cout << "\n10-Subtraction one Decade is: ";
	PrintDate(Date);

	Date = DecreaseDateByXDecade(10, Date);
	cout << "\n11-Subtraction 10 Decade is: ";
	PrintDate(Date);

	Date = DecreaseDateByXDecadeFaster(10, Date);
	cout << "\n12-Subtraction 10 Decade (faster) is: ";
	PrintDate(Date);

	Date = DecreaseDateByOneCentury(Date);
	cout << "\n13-Subtraction One Century is: ";
	PrintDate(Date);

	Date = DecreaseDateByOneMillennium(Date);
	cout << "\n14-Subtraction One Millennium is: ";
	PrintDate(Date);


	system("pause>0");

	return 0;
}