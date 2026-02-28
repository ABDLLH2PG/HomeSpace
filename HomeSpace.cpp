#include <iostream>
#include <string> 
#include "MyInputLib.h" 

// [C07] Problem #27: Invert Charcter Case [My Solution]
using namespace std;

char InvertingCharacterCase(char ch)
{
	if (ch >= 65 && ch <= 97)
		return (ch = tolower(ch));
	else
		return (ch = toupper(ch));
}


int main()
{
	char character = MyInputLib::ReadChar("Please Enter a Character ?");

	cout << "\nChar after inverting case:\n";
	character = InvertingCharacterCase(character);
	cout << character;

	system("pause>0");

	return 0;
}