#include <iostream>
#include <string> 
#include "MyInputLib.h" 

// [C07] Problem #29: Count Small/Capital Letters [My Solution]
using namespace std;

int CountCapitalLetters(string S1)
{
	int Count = 0;

	for (int i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]))
			Count++;
	}

	return Count;
}

int CountSmallLetters(string S1)
{
	int Count = 0;

	for (int i = 0; i < S1.length(); i++)
	{
		if (islower(S1[i]))
			Count++;
	}

	return Count;
}

int main()
{
	string S1 = MyInputLib::ReadString("Please Enter Your String?");

	cout << "\nString Length = " << S1.length();
	cout << "\nCapital Letters Count = " << CountCapitalLetters(S1);
	cout << "\nSmall Letters Count = " << CountSmallLetters(S1);
	
	system("pause>0");

	return 0;
}