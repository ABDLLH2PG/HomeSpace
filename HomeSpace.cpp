#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #36: Count Each Word In String [My Solution]
using namespace std;

short CountEachWordInString(string S1)
{
	short Counter = 0;
	string delim = " ";
	short pos = 0;
	string sWord;

	while ((pos = S1.find(delim)) != string::npos)
	{
		sWord = S1.substr(0, pos);

		if (sWord != "")
		{
			Counter++;
		}

		S1.erase(0, pos + delim.length());
		
	}

	if (S1 != "")
	{
		Counter++;
	}

	return Counter;
}

int main()
{
	string S1 = MyInputLib::ReadString("Please Enter Your String ?");

	cout << "\nThe number of words in your string is: " 
		<< CountEachWordInString(S1) << endl;
	


	system("pause>0");

	return 0;
}