#include <iostream>
#include <string>
#include <vector>
#include "MyInputLib.h"

// [C07] Problem #37: Count Each Word In String [Optimized code]
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


int main()
{
	string S1 = MyInputLib::ReadString("Please Enter Your String ?");

	vector <string> vString = SplitString(S1, " ");

	cout << "Tokens = " << vString.size() << endl;

	for (string &s : vString)
	{
		cout << s << endl;
	}

	system("pause>0");


	return 0;
}