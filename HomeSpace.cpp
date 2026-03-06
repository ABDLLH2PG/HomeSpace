#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #32: Is Vowel? [Optimized Code]
using namespace std;

bool IsVowel(char Letter)
{
	Letter = tolower(Letter);

	return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));
}


int main()
{
	char Ch1 = MyInputLib::ReadChar("Please Enter a Character ?");

	if (IsVowel(Ch1))
		cout << "\nYES Letter \'" << Ch1 << "\' is vowel\n";
	else
		cout << "\nNO Letter \'" << Ch1 << "\' is Not vowel\n";


	system("pause>0");

	return 0;
}