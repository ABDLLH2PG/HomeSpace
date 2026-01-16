#include <iostream>
using namespace std;

// Lesson #40 - Pointers and Arrays [Extra Example]
int main()
{
	int arr[4] = {10, 20, 30, 40};
	int *ptr;
	ptr = arr;

	// ptr is equivalent to &arr[0];
	// ptr + 1 is equivalent to &arr[1];
	// ptr + 2 is equivalent to &arr[2];
	// ptr + 3 is equivalent to &arr[3];


	cout << "Addresses are:\n";
	for (int i = 0; i < 4; i++)
		cout << ptr + i << endl;

	cout << "\nValue are: \n";
	for (int j = 0; j < 4; j++)
		cout << *(ptr + j) << endl;

	return 0;
}