#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #35: Print Each Word In String[Optimized Code]
using namespace std;

void PrintEachWordInString(string S1)
{
	cout << "\nYour string words are:\n\n";

	string delim = " "; // delimiter
	short pos = 0;
	string sWord; // define a string variable

	// use find() function to get the position of the delimiters
	while ((pos = S1.find(delim)) != string::npos)
	{
		sWord = S1.substr(0, pos); // store the word

		if (sWord != "")
		{
			cout << sWord << endl;
		}

		S1.erase(0, pos + delim.length()); 
		/* erase() until position and move to next word. */
	}

	if (S1 != "")
	{
		cout << S1 << endl; // it print last word of the string.
	}

}


int main()
{
	string S1 = MyInputLib::ReadString("Please Enter Your String ?");

	PrintEachWordInString(S1);


	system("pause>0");

	return 0;
}