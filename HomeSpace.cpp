#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #42: Replace Words [My Solution]
using namespace std;

string ReplaceWords(string S1, string Originalword, string ReplaceWord)
{
	short pos = 0;

	while ((pos = S1.find(Originalword)) != string::npos)
	{
		S1.erase(pos, Originalword.length());
		S1.insert(pos, ReplaceWord);
	}

	return S1;
}


int main()
{
	string S1 = "Welcome to Jordan , Jordan is a nice country";
	cout << "\nOrigial String\n" << S1;

	cout << "\n\nString After Replace:\n";
	cout << ReplaceWords(S1, "Jordan", "USA");



	system("pause>0");

	return 0;
}