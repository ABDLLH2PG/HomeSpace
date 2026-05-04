#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #07: Day Name [Optimized Code]

short DayOfWeekOrder(short Year, short Month, short Day)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	return arrDayNames[DayOfWeekOrder];
}


int main()
{
	short Year = MyInputLib::ReadNumber("\nPlease enter a year? ");
	short Month = MyInputLib::ReadNumber("\nPlease enter a Month? ");
	short Day = MyInputLib::ReadNumber("\nPlease enter a Day? ");

	cout << "\nDate      :" << Day << "/" << Month << "/" << Year;
	cout << "\nDay Order : " << DayOfWeekOrder(Year, Month, Day);
	cout << "\nDay Name  : " << DayShortName(DayOfWeekOrder(Year, Month, Day));



	system("pause>0");

	return 0;
}