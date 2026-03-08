#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #34: Print All Vowels In String [Optimized Code]
using namespace std;

bool IsVowel(char Letter)
{
	Letter = tolower(Letter);

	return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));
}

void PrintVowels(string S1)
{
	cout << "\nVowels in string are: ";

	for (short i = 0; i < S1.length(); i++)
	{
		if (IsVowel(S1[i]))
			cout << S1[i] << "   ";
	}
}


int main()
{
	string S1 = MyInputLib::ReadString("Please Enter Your String?");

	PrintVowels(S1);


	system("pause>0");

	return 0;
}