#include <iostream>
#include <vector>
using namespace std;

// Lesson #46 - Access Elements
int main()
{
	vector <int> vNum{ 1, 2, 3, 4, 5 };

	cout << "\n\n using .at(i) \n";
	cout << "Element at Index 0: " << vNum.at(0) << endl;
	cout << "Element at Index 2: " << vNum.at(2) << endl;
	cout << "Element at Index 4: " << vNum.at(4) << endl;

	
	cout << "\n\n using [i]\n";
	cout << "Element at Index 0: " << vNum[0] << endl;
	cout << "Element at Index 2: " << vNum[2] << endl;
	cout << "Element at Index 4: " << vNum[4] << endl;

	
	return 0;
}