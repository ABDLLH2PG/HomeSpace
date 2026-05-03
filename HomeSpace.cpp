#include <iostream>
#include <string>
#include "MyLib/MyInputLib.h"
using namespace std;

// [C08] Problem #02: Leap Year [My Solution]

bool CheckLeapYear(int Year)
{
	if (Year % 400 == 0)
	{
		return true;
	}
	else
	{
		if (Year % 4 == 0 && Year % 100 != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool CheckLeapYear2(int Year)
{
	return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}

int main()
{
	int Year = MyInputLib::ReadNumber("Enter a Year? ");

	if (CheckLeapYear(Year))
	{
		cout << Year << " is Leap Year.";
	}
	else
	{
		cout << Year << " is Not Leap Year.";
	}


	system("pause>0");

	return 0;
}