#include <iostream>
using namespace std;

//Lesson #20 - Static Variables
void MyFunc()
{
	static int Number = 1;
	cout << "Value of Number: " << Number << "\n";

	Number++;
}

int main()
{
	MyFunc();
	MyFunc();
	MyFunc();


	return 0;
}