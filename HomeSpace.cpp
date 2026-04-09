#include <iostream>
#include <string>
#include <vector>

// [C07] Problem #39:  Join String [My Solution]
using namespace std;

string JoinString(vector <string> vString, string delim)
{
	string S1 = "";

	for (short i = 0; i < vString.size() - 1; i++)
	{
		S1 += vString[i] + delim;
	}

	S1 += vString[vString.size() - 1];

	return S1;
}


int main()
{
	vector <string> vName = { "Mohammed", "Faid", "Ali", "Maher" };

	cout << "Vector after join:\n";
	cout << JoinString(vName, " ");


	system("pause>0");

	return 0;
}