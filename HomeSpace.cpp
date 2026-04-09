#include <iostream>
#include <string>
#include <vector>

// [C07] Problem #39:  Join String [Optimized Code]
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


int main()
{
	vector <string> vName = { "Mohammed", "Faid", "Ali", "Maher" };

	cout << "\nVector after join:\n";
	cout << JoinString(vName, " ");


	system("pause>0");

	return 0;
}