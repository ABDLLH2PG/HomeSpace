#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #30: Count Letters [My Solution]
using namespace std;

short CountLetters(string S1, char Ch1)
{
	short Counter = 0;

	for (int i = 0; i < S1.length(); i++)
	{
		if (S1[i] == Ch1)
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

	cout << "\nLetter '" << Ch1 << "' Count = " << CountLetters(S1, Ch1);


	system("pause>0");

	return 0;
}