#include <iostream>
#include <string> 
#include "MyInputLib.h" 

// [C07] Problem #28: Invert All Letters Case [Optimized Code]
using namespace std;

char InvertLetterCase(char char1)
{
	return isupper(char1) ? tolower(char1) : toupper(char1);
}

string InvertAllStringLetterCase(string S1)
{
	for (int i = 0; i < S1.length(); i++)
	{
		S1[i] = InvertLetterCase(S1[i]);
	}

	return S1;
}


int main()
{
	string S1 = MyInputLib::ReadString("Please Enter Your String?");

	cout << "\nString after Inverting All Letters Case:\n";
	S1 = InvertAllStringLetterCase(S1);
	cout << S1 << endl;

	system("pause>0");

	return 0;
}