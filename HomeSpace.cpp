#include <iostream>
#include <string> 
#include "MyInputLib.h" 

// [C07] Problem #26: Upper/Lower All Letters of a String [Optimized Code]
using namespace std;

string UpperAllString(string S1)
{
	for (int i = 0; i < S1.length(); i++)
	{
		S1[i] = toupper(S1[i]);
	}

	return S1;
}

string LowerAllString(string S1)
{
	for (int i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}

	return S1;
}


int main()
{
	string S1 = MyInputLib::ReadString("Please Enter Your String ?");

	cout << "\nString after Upper:\n";
	S1 = UpperAllString(S1);
	cout << S1 << endl;

	cout << "\nString after Lower:\n";
	S1 = LowerAllString(S1);
	cout << S1 << endl;

	system("pause>0");

	return 0;
}