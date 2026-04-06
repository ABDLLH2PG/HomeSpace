#include <iostream>
#include <string>

// [C07] Problem #38: Trim Left / Trim Right / Trim [My Solution]
using namespace std;

string TrimLeft(string S1)
{
	short pos = 0;
	char delim = ' ';

	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != delim)
		{
			pos = i;
			break;
		}
	}

	S1.erase(0, pos);

	return S1;
}

string TrimRight(string S1)
{
	short pos = 0;
	short LastChar = S1.length() - 1;
	char delim = ' ';

	for (short i = LastChar; i > 0; i--)
	{
		if (S1[i] != delim)
		{
			pos = i;
			break;
		}
	}

	S1.erase(pos + 1, LastChar);

	return S1;
}

string Trim(string S1)
{
	S1 = TrimLeft(S1);
	S1 = TrimRight(S1);

	return S1;
}


int main()
{
	string S1 = "     Mohammed Abu-Hadhoud     ";

	cout << "\nString     = " << S1 << endl;
	cout << "\nTrim Left  = " << TrimLeft(S1);
	cout << "\nTrim Right = " << TrimRight(S1);
	cout << "\nTrim       = " << Trim(S1);


	system("pause>0");

	return 0;
}