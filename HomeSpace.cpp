#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #42: Replace Words [Optimized Code]
using namespace std;

string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string ReplaceTo)
{
	short pos = S1.find(StringToReplace);

	while (pos != string::npos)
	{
		S1.replace(pos, StringToReplace.length(), ReplaceTo);
		pos = S1.find(StringToReplace); // find next
	}

	return S1;
}


int main()
{
	string S1 = "Welcome to Jordan , Jordan is a nice country";
	cout << "\nOrigial String\n" << S1;

	cout << "\n\nString After Replace:\n";
	cout << ReplaceWordInStringUsingBuiltInFunction(S1, "Jordan", "USA");



	system("pause>0");

	return 0;
}