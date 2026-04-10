#include <iostream>
#include <string>
#include <vector>
#include "MyInputLib.h"

// [C07] Problem #41: Reverse Words [My Solution]
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

string ReverseWords(string S1, string Delim = " ")
{
	vector <string> vString = SplitString(S1, Delim);

	S1 = "";

	for (int i = vString.size() - 1; i >= 0; i--)
	{
		S1 = S1 + vString[i] + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());

}


int main()
{
	string S1 = MyInputLib::ReadString("Please Enter Your String?");

	cout << "\n\nStrign after reversing words:\n" << ReverseWords(S1);



	system("pause>0");

	return 0;
}