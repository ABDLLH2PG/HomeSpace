#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #24: Upper First Letter of Each Word [My Solution]
using namespace std;

string UpperFirstLetterOfEachWord(string S1)
{
	string S2 = "";
	bool isFirstLetter = true;

	for (int i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && isFirstLetter)
		{
			S1[i] = toupper(S1[i]);
		}

		S2 += S1[i];

		isFirstLetter = (S1[i] == ' ' ? true : false);
	}

	return S2;
}


int main()
{
	string S1 = MyInputLib::ReadString("Please Enter Your String ?");

	cout << "\nString after conversion:\n";
	cout << UpperFirstLetterOfEachWord(S1) << endl;

	system("pause>0");

	return 0;
}