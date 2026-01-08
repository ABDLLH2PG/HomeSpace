#include <iostream>
#include <vector>
using namespace std;

//Lesson #28 - Introduction, Declaration and Initialization
int main()
{
	// std::vector<T> vector_name;

	vector <int> vNumbers = { 10, 20, 30, 40, 50 };

	cout << "Numbers Vector = ";

	for (int &Number : vNumbers)
	{
		cout << Number << "  ";
	}

	cout << endl;

	return 0;
}