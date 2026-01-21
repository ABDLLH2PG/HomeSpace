#include <iostream>
#include <cctype>
using namespace std;

// Lesson #51 - Some CCTYPE Functions
int main()
{
	char x;
	char w;

	x = toupper('a');
	w = tolower('A');

	cout << "Converting a to A: " << x << endl;
	cout << "Converting A to a: " << w << endl;

	// Digits (A to Z)
	// returns zero if not, and non zero if yes
	cout << "isupper('A') " << isupper('A') << endl;

	// lower case (a to z)
	// returns zero if not, and non zero if yes
	cout << "islower('a') " << islower('a') << endl;

	// Digits (0 to 9)
	// returns zero if not, and non zero if yes
	cout << "isdigit('9') " << isdigit('9') << endl;

	// punctuation characters are !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
	// return zero if not, and non zero if yes
	cout << "ispunct(';') " << ispunct(';') << endl;


	return 0;
}