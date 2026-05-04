#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #07: Day Name [My Solution]

void PrintDate(short Year, short Month, short Day)
{
	cout << Day << "/" << Month << "/" << Year;
}

short DayOrder(short Year, short Month, short Day)
{
	int a = ((14 - Month) / 12);
	int y = Year - a;
	int m = Month + 12 * a - 2;

	int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	
	return d;
}

string DayName(short DayOrder)
{
	string DayName[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	return DayName[DayOrder];
}


int main()
{
	short Year = MyInputLib::ReadNumber("\nPlease enter a year? ");

	short Month = MyInputLib::ReadNumber("\nPlease enter a Month? ");

	short Day = MyInputLib::ReadNumber("\nPlease enter a Day? ");

	cout << "\nDate      :";    PrintDate(Year, Month, Day);
	cout << "\nDay Order : " << DayOrder(Year, Month, Day);
	cout << "\nDay Name  : " << DayName(DayOrder(Year, Month, Day));



	system("pause>0");

	return 0;
}