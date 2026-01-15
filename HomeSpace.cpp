#include <iostream>
using namespace std;

// Lesson #39 - Call by Reference: Using pointers
void Swap(int *n1, int *n2)
{
	int temp;
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}


int main()
{
	int a = 1, b = 2;
	
	cout << "Before swapping" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	Swap(&a, &b);

	cout << "\nAfter swapping" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;


	return 0;
}