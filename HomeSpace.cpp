#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #23: Print First Letter of Each Word [My Solution]
using namespace std;

void PrintFirstLetterOfEachWord(string S1)
{
	cout << S1[0] << endl;

	for (int i = 0; i < S1.length() - 1; i++)
	{
		if (S1[i + 1] == ' ')
		{
			cout << S1[i + 1 + 1] << endl;
		}
	}
}


int main()
{
	string S1 = MyInputLib::ReadString("Please Enter Your String ?");

	PrintFirstLetterOfEachWord(S1);

	system("pause>0");

	return 0;
}