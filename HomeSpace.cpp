#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #29: Count Small/Capital Letters [Optimized Code]
using namespace std;

enum enWhatToCount { CapitalLetters = 0, SmallLetters = 1, All = 2 };

short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
{
	if (WhatToCount == enWhatToCount::All)
	{
		return S1.length();
	}

	short Counter = 0;

	for (int i = 0; i < S1.length(); i++)
	{
		if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
		{
			Counter++;
		}

		if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
		{
			Counter++;
		}
	}

	return Counter;
}

short CountCapitalLetters(string S1)
{
	short Counter = 0;

	for (int i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]))
		{
			Counter++;
		}
	}

	return Counter;
}

short CountSmallLetters(string S1)
{
	short Counter = 0;

	for (int i = 0; i < S1.length(); i++)
	{
		if (islower(S1[i]))
		{
			Counter++;
		}
	}

	return Counter;
}

int main()
{
	string S1 = MyInputLib::ReadString("Please Enter Your String?");

	cout << "\nString Length = " << S1.length();
	cout << "\nCapital Letters Count = " << CountCapitalLetters(S1);
	cout << "\nSmall Letters Count = " << CountSmallLetters(S1);

	cout << "\n\nMethod 2:\n";

	cout << "\nString Length = " << CountLetters(S1);
	cout << "\nCapital Letters Count = " << CountLetters(S1, enWhatToCount::CapitalLetters);
	cout << "\nSmall Letters Count = " << CountLetters(S1, enWhatToCount::SmallLetters);


	system("pause>0");

	return 0;
}