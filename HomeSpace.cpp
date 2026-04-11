#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #43: Replace Words (Custom) [My Solution]
using namespace std;

string LowerAllString(string S1)
{
	for (int i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}

	return S1;
}


string ReplaceWordInString(string S1, string StringToReplace, string ReplaceTo, bool MatchCase = false)
{
	string S2 = S1;

	if (!MatchCase)
	{
		S2 = LowerAllString(S2);
		StringToReplace = LowerAllString(StringToReplace);

	}

	short pos = S2.find(StringToReplace);

	while (pos != string::npos)
	{
		S2 = S2.erase(pos, StringToReplace.length());
		S2 = S2.insert(pos, ReplaceTo);
		pos = S2.find(StringToReplace);
	}

	return S2;
}


int main()
{
	string S1 = "Welcome to Jordan , Jordan is a nice country";
	cout << "\nOrigial String\n" << S1;

	cout << "\n\nReplace with match case:\n";
	cout << ReplaceWordInString(S1, "jordan", "USA", false);

	cout << "\n\nReplace with dont match case:\n";
	cout << ReplaceWordInString(S1, "Jordan", "USA", true);




	system("pause>0");

	return 0;
}