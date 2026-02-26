#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #26: Upper/Lower All Letters of a String [My Solution]
using namespace std;

string UpperAllLettersOfString(string S1)
{
	for (int i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]) || islower(S1[i]))
		{
			S1[i] = toupper(S1[i]);
		}
	}

	return S1;
}

string LowerAllLettersOfString(string S1)
{
	for (int i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]) || islower(S1[i]))
		{
			S1[i] = tolower(S1[i]);
		}
	}

	return S1;
}


int main()
{
	string S1 = MyInputLib::ReadString("Please Enter Your String ?");

	cout << "\nString after Upper:\n";
	cout << UpperAllLettersOfString(S1) << endl;

	cout << "\nString after Lower:\n";
	cout << LowerAllLettersOfString(S1) << endl;


	system("pause>0");

	return 0;
}