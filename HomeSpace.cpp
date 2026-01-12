#include <iostream>
#include <vector>
using namespace std;

// Lesson #31 - Remove elements
int main()
{
	vector <int> vNumbers;

	vNumbers.push_back(10);
	vNumbers.push_back(20);
	vNumbers.push_back(30);
	vNumbers.push_back(40);
	vNumbers.push_back(50);

	// The pop_back Function remove 1 value (the last value enter the vector);
	vNumbers.pop_back();
	vNumbers.pop_back();
	vNumbers.pop_back();
	vNumbers.pop_back();
	vNumbers.pop_back();
	

	// The empty Function return true or false if vector is empty or not;
	if (!vNumbers.empty())
		vNumbers.pop_back();

	// The size Function return number of stack value in vector;
	// The clear Function clear all value in vector;
	if (vNumbers.size() > 0)
		vNumbers.clear();


	cout << "Numbers Vector: \n\n";

	//ranged loop
	for (int& Number : vNumbers)
	{
		cout << Number << endl;
	}

	cout << endl;

	return 0;
}