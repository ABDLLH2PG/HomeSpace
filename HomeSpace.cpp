#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #31: Count Letter (Match Case) [Optimized Code]
using namespace std;

char InvertLetterCase(char char1)
{
	return isupper(char1) ? tolower(char1) : toupper(char1);
}

short CountLetter(string S1, char Letter, bool MatchCase = true)
{
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (MatchCase)
		{
			if (S1[i] == Letter)
				Counter++;
		}
		else
		{
			if (tolower(S1[i]) == tolower(Letter))
				Counter++;
		}
	}

	return Counter;
}


int main()
{
	string S1 = MyInputLib::ReadString("Please Enter Your String ?");
	char Ch1 = MyInputLib::ReadChar("\nPlease Enter a Character ?");

	cout << "\nLetter \'" << Ch1 << "\' Count = " << CountLetter(S1, Ch1);
	cout << "\nLetter \'" << Ch1 << "\'" << " Or \'" << InvertLetterCase(Ch1) << "\'  Count = " << CountLetter(S1, Ch1, false);


	system("pause>0");

	return 0;
}