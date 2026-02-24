#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #23: Print First Letter of Each Word [Optimized Code]
using namespace std;

void PrintFirstLetterOfEachWord(string S1)
{
	bool isFirstLetter = true;

	for (int i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && isFirstLetter)
		{
			cout << S1[i] << endl;
		}

		isFirstLetter = (S1[i] == ' ' ? true : false);
	}
}


int main()
{
	string S1 = MyInputLib::ReadString("Please Enter Your String ?");

	PrintFirstLetterOfEachWord(S1);

	system("pause>0");

	return 0;
}