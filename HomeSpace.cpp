#include <iostream>
using namespace std;

// Lesson #43 - Memory Management: new and delete
int main()
{
	// declare an int pointer
	int *ptrX;

	// declare a float pointer
	float *ptrY;

	// dynamically allocate memory
	ptrX = new int;
	ptrY = new float;

	// assigning value to the memory
	*ptrX = 45;
	*ptrY = 58.35f;

	cout << *ptrX << endl;
	cout << *ptrY << endl;

	// deallocate the memory
	delete ptrX;
	delete ptrY;


	return 0;
}