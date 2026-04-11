#include <iostream>
#include <string>

// [C07] Problem #44: Remove Punctuations [Optimized Code]
using namespace std;

string RemovedPauncuationsFromString(string S1)
{
	string S2 = "";

	for (int i = 0; i < S1.length(); i++)
	{
		if (!ispunct(S1[i]))
		{
			S2 += S1[i];
		}
	}

	return S2;
}


int main()
{
	string S1 = "Welcome to Jordan, Jordan is a nice country; it's amazing.";
	cout << "\nOriginal String:\n" << S1;

	cout << "\n\nPauncuations Removed:";
	cout << "\n" << RemovedPauncuationsFromString(S1);


	system("pause>0");

	return 0;
}