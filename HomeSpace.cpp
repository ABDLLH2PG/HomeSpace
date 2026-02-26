#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #25: Lower First Letter of Each Word [My Solution]
using namespace std;

string LowerFirstLetterOfEachWord(string S1)
{
	bool isFirstLetter = true;

	for (int i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && isFirstLetter)
		{
			S1[i] = tolower(S1[i]);
		}

		isFirstLetter = (S1[i] == ' ' ? true : false);
	}

	return S1;
}


int main()
{
	string S1 = MyInputLib::ReadString("Please Enter Your String ?");

	cout << "\nString after conversion:\n";
	S1 = LowerFirstLetterOfEachWord(S1);
	cout << S1 << endl;

	system("pause>0");

	return 0;
}