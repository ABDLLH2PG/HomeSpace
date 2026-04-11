#include <iostream>
#include <string>

// [C07] Problem #44: Remove Punctuations [My Solution]
using namespace std;

string RemovedPauncuationsInString(string S1)
{
	for (int i = 0; i < S1.length(); i++)
	{
		if (ispunct(S1[i]) > 0)
		{
			S1.erase(i, 1);
		}
	}

	return S1;
}


int main()
{
	string S1 = "Welcome to Jordan, Jordan is a nice country; it's amazing.";
	cout << "\nOriginal String:\n" << S1;

	cout << "\n\nPauncuations Removed:";
	cout << "\n" << RemovedPauncuationsInString(S1);


	system("pause>0");

	return 0;
}