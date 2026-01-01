#include <iostream>
using namespace std;

//Visual Studio Function Tips
//1- Go To Definition
//2- Go To Declaration
//3- View Call Hierarchy
//4- Find All References
//5- Peek Definition
//6- Rename Function

void Function2();

void koko()
{
	cout << "Hi I'm function4 " << endl;
}

void Function3()
{
	koko();
}

void Function2()
{
	Function3();
}

void Function1()
{
	Function2();
	koko();
}


int main()
{
	Function1();

	

	return 0;
}