#include <iostream>
using namespace std;

// Lesson #37 - Common Mistakes with Pointers 
int main()
{
	int x, * p;

	// Wrong!
	// p is an address but x is not
	//p = x;
	
	// Correct!
	// p is an address and so is &x
	p = &x;

	// Wrong!
	// &x is and address
	// *p is the value stored in &x
	//*p = &x;

	// Correct!
	// *p is the value and so x
	*p = x;


	return 0;
}