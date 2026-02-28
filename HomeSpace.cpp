#include <iostream>
#include <string> 
#include "MyInputLib.h" 

// [C07] Problem #27: Invert Charcter Case [Optimized Code]
using namespace std;

char InvertLetterCase(char char1)
{
	return isupper(char1) ? tolower(char1) : toupper(char1);
}


int main()
{
	char Ch1 = MyInputLib::ReadChar("Please Enter a Character ?");

	cout << "\nChar after Inverting case:\n";
	Ch1 = InvertLetterCase(Ch1);
	cout << Ch1 << endl;

	system("pause>0");

	return 0;
}