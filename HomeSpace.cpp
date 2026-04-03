#include <iostream>
#include <string>
#include <vector>
#include "MyInputLib.h"

// [C07] Problem #37: Count Each Word In String [My Solution]
using namespace std;

void SplitWord(string S1, string delim = " ")
{
	short Tokens = 0;
	short pos = 0;
	string sWord;
	vector <string> vWords;

	while ((pos = S1.find(delim)) != string::npos)
	{
		sWord = S1.substr(0, pos);

		if (sWord != "")
		{
			vWords.push_back(sWord);
			Tokens++;
		}

		S1.erase(0, pos + delim.length());
	}

	if (S1 != "")
	{
		vWords.push_back(S1);
		Tokens++;
	}

	cout << "Tokens = " << Tokens << "\n";

	for (string &vWord : vWords)
	{
		cout << vWord << "\n";
	}
}


int main()
{
	string S1 = MyInputLib::ReadString("Please Enter Your String ?");
	
	SplitWord(S1);


	system("pause>0");

	return 0;
}