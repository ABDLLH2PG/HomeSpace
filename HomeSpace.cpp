#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #13: Date 1 Less Than Date 2 [Optimized Code]

struct sDate
{
	short Year;
	short Month;
	short Day;
};

sDate ReadFullDate()
{
	sDate Date;

	Date.Day = MyInputLib::ReadNumber("\nPlease enter a Day? ");
	Date.Month = MyInputLib::ReadNumber("Please enter a Month? ");
	Date.Year = MyInputLib::ReadNumber("Please enter a Year? ");

	return Date;
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) 
		? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month 
			? Date1.Day < Date2.Day : false)) : false);
}


int main()
{
	sDate Date1 = ReadFullDate();
	sDate Date2 = ReadFullDate();

	if (IsDate1BeforeDate2(Date1, Date2))
		cout << "\nYes, Date1 is Less than Date2.";
	else
		cout << "\nNo, Date1 is Not Less than Date2.";


	system("pause>0");

	return 0;
}