#include <iostream>
#include <string>
#include <vector>

// [C07] Problem #40: Join String (Overloading) [My Solution]
using namespace std;

string JoinString(vector <string> vString, string Delim)
{
	string S1 = "";

	for (string& s : vString)
	{
		S1 = S1 + s + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());
}

string JoinString(string arrString[], short arrLength, string Delim)
{
	string S1 = "";

	for (short i = 0; i < arrLength; i++)
	{
		S1 = S1 + arrString[i] + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());
}

int main()
{
	vector <string> vName = { "Mohammed", "Faid", "Ali", "Maher" };
	string arrString[4] = { "Mohammed", "Faid", "Ali", "Maher" };
	short arrLength = 4;

	cout << "\nVector after join:\n";
	cout << JoinString(vName, " ");

	cout << "\nVector after join:\n";
	cout << JoinString(arrString, arrLength, " ");

	system("pause>0");

	return 0;
}