#include <iostream>
using namespace std;

// Lesson #35 - What is Pointer?
int main()
{
	int a = 10;
	
	cout << "a value        = " << a << endl;
	cout << "a address      = " << &a << endl;

	int * p = &a;


	cout << "Pointer Value  = " << p;

	cout << endl;

	return 0;
}