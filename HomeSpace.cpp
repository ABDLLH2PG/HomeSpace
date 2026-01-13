#include <iostream>
using namespace std;

// Lesson #33 - Call ByRef/ByVal Important Review. 
void Function1(int &x)
{
	x++;
}


int main()
{
	int a = 10;

	cout << a << endl;
	cout << &a << endl;

	Function1(a);

	cout << "\na after calling function1 = " << a << endl;


	return 0;
}