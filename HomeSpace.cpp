#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #31: Count Letter (Match Case) [My Solution]
using namespace std;

short CountLetters(string S1, char Letter)
{
	short Counter = 0;

	for (int i = 0; i < S1.length(); i++)
	{
		if (S1[i] == Letter)
		{
			Counter++;
		}
	}

	return Counter;
}

char MatchLetterCase(string S1, char Letter)
{
	if (Letter >= 65 && Letter <= 90)
	{
		return char(Letter + 32);
	}

	if (Letter >= 97 && Letter <= 122)
	{
		return char(Letter - 32);
	}

	else
	{
		return Letter;
	}
}

short CountLettersMatchCase(string S1, char Letter)
{
	short Counter = 0;
	char Ch2 = MatchLetterCase(S1, Letter);

	for (int i = 0; i < S1.length(); i++)
	{
		if (S1[i] == Letter || S1[i] == Ch2)
		{
			Counter++;
		}
	}

	return Counter;
}


int main()
{
	string S1 = MyInputLib::ReadString("Please Enter Your String ?");

	char Ch1 = MyInputLib::ReadChar("\nPlease Enter a Character ?");

	char Ch2 = MatchLetterCase(S1, Ch1);

	cout << "\nLetter '" << Ch1 << "' Count = " << CountLetters(S1, Ch1);

	cout << "\nLetter '" << Ch1 << "' Or '" << Ch2 << "'  Count = " << CountLettersMatchCase(S1, Ch1);

	system("pause>0");

	return 0;
}