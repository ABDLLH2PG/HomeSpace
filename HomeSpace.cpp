#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #20-32: Increase Date Problems [Optimized Code]

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

stDate IncreaseDateByXDays(short Days, stDate Date)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}

	return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
	for (short i = 1; i <= 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}

	return Date;
}

stDate IncreaseDateByXWeeks(short Weeks, stDate Date)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}

	return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}

	//last check day in date should not exceed max days in the current month
	// example if date is 31/1/2022 increasing one month should 
	// not be 31 / 2 / 2022, it should be 28/2/2022

	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

stDate IncreaseDateByXMonth(short Months, stDate Date)
{
	for (int i = 1; i <= Months; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}

	return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
	Date.Year++;
	return Date;
}

stDate IncreaseDateByXYears(short Years, stDate Date)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}

	return Date;
}

stDate IncreaseDateByXYearsFaster(short Years, stDate Date)
{
	Date.Year += Years;
	return Date;
}

stDate IncreaseDateByOneDecades(stDate Date)
{
	Date.Year += 10;
	return Date;
}

stDate IncreaseDateByXDecades(short Decades, stDate Date)
{
	for (short i = 1; i <= Decades * 10; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}

	return Date;
}

stDate IncreaseDateByXDecadesFaster(short Decades, stDate Date)
{
	Date.Year += Decades * 10;
	return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
	Date.Year += 100;
	return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
	Date.Year += 1000;
	return Date;
}


int main()
{
	stDate Date = ReadFullDate();
	cout << "\nDate After:\n";

	Date = IncreaseDateByOneDay(Date);
	cout << "\n01-Adding one day is: ";
	PrintDate(Date);

	Date = IncreaseDateByXDays(10, Date);
	cout << "\n02-Adding 10 days is: ";
	PrintDate(Date);

	Date = IncreaseDateByOneWeek(Date);
	cout << "\n03-Adding one week is: ";
	PrintDate(Date);

	Date = IncreaseDateByXWeeks(10, Date);
	cout << "\n04-Adding 10 weeks is: ";
	PrintDate(Date);

	Date = IncreaseDateByOneMonth(Date);
	cout << "\n05-Adding one month is: ";
	PrintDate(Date);

	Date = IncreaseDateByXMonth(5, Date);
	cout << "\n06-Adding 5 months is: ";
	PrintDate(Date);

	Date = IncreaseDateByOneYear(Date);
	cout << "\n07-Adding one year is: ";
	PrintDate(Date);

	Date = IncreaseDateByXYears(10, Date);
	cout << "\n08-Adding 10 Years is: ";
	PrintDate(Date);

	Date = IncreaseDateByXYearsFaster(10, Date);
	cout << "\n09-Adding 10 Years (faster) is: ";
	PrintDate(Date);

	Date = IncreaseDateByOneDecades(Date);
	cout << "\n10-Adding one Decade is: ";
	PrintDate(Date);

	Date = IncreaseDateByXDecades(10, Date);
	cout << "\n11-Adding 10 Decades is: ";
	PrintDate(Date);

	Date = IncreaseDateByXDecadesFaster(10, Date);
	cout << "\n11-Adding 10 Decades (faster) is: ";
	PrintDate(Date);

	Date = IncreaseDateByOneCentury(Date);
	cout << "\n12-Adding One Century is: ";
	PrintDate(Date);

	Date = IncreaseDateByOneMillennium(Date);
	cout << "\n13-Adding One Millennium is: ";
	PrintDate(Date);


	system("pause>0");

	return 0;
}