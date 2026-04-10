#include <iostream>
#include <string>
#include <vector>
#include "MyInputLib.h"

// [C07] Problem #41: Reverse Words [Optimized Code]
using namespace std;

vector <string> SplitString(string S1, string Delim = " ")
{
	vector <string> vString;

	short pos = 0;
	string sWord;

	while ((pos = S1.find(Delim)) != string::npos)
	{
		sWord = S1.substr(0, pos);

		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		S1.erase(0, pos + Delim.length());
	}

	if (S1 != "")
	{
		vString.push_back(S1);
	}

	return vString;
}

string ReverseWordsInString(string S1)
{
	vector <string> vString = SplitString(S1, " ");
	S1 = "";

	// declare iterator
	vector <string>::iterator iter = vString.end();

	while (iter != vString.begin())
	{
		--iter;

		S1 += *iter + " ";
	}

	return S1.substr(0, S1.length() - 1); // remove last space.
}


int main()
{
	string S1 = MyInputLib::ReadString("Please Enter Your String?");

	cout << "\n\nStrign after reversing words:";
	cout << "\n" << ReverseWordsInString(S1);



	system("pause>0");

	return 0;
}