#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #32: Is Vowel? [My Solution]
using namespace std;

bool IsVowel(char Letter)
{
	char Vowel[5] = {'a','e','i','o','u'};

	for (short i = 0; i < 5; i++)
	{
		if (tolower(Letter) == Vowel[i])
		{
			return true;
		}
	}

	return false;
}


int main()
{
	char Ch1 = MyInputLib::ReadChar("Please Enter a Character ?");

	if (IsVowel(Ch1))
		cout << "\nYES Letter \'" << Ch1 << "\' is vowel\n";
	else
		cout << "\nNO Letter \'" << Ch1 << "\' is not vowel\n";


	system("pause>0");

	return 0;
}