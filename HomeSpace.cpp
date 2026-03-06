#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #33: Count Vowel[My Solution]
using namespace std;

bool IsVowel(char Letter)
{
	Letter = tolower(Letter);

	return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));
}

short CountVowel(string S1)
{
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (IsVowel(tolower(S1[i])))
		{
			Counter++;
		}
	}

	return Counter;
}


int main()
{
	string S1 = MyInputLib::ReadString("Please Enter Your String ?");

	cout << "\nNumber of vowels is: " << CountVowel(S1) << endl;


	system("pause>0");

	return 0;
}