#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #36: Count Each Word In String [Optimized Code]
using namespace std;

short CountWords(string S1)
{
	string delim = " "; // delimiter
	short Counter = 0;
	short pos = 0;
	string sWord; // define a string variable

	// use find() function to get the position of the delimiters
	while ((pos = S1.find(delim)) != string::npos)
	{
		sWord = S1.substr(0, pos); // store the word

		if (sWord != "")
		{
			Counter++;
		}

		S1.erase(0, pos + delim.length());
		/* erase() until position and move to next word. */
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

	cout << "\nThe number of words in your string is: " << CountWords(S1) << endl;
	


	system("pause>0");

	return 0;
}