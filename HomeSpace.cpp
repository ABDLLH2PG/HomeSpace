#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #35: Print Each Word In String [MySolution]
using namespace std;

void PrintEachWord(string S1)
{
	for (int i = 0; i < S1.length(); i++)
	{
		if (S1[i] == ' ')
		{
			cout << endl;
			continue;
		}

		cout << S1[i];
	}
}


int main()
{
	string S1 = MyInputLib::ReadString("Please Enter Your String?");

	cout << "\nYour String Words are:\n";

	PrintEachWord(S1);

	system("pause>0");

	return 0;
}