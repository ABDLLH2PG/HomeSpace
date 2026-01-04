#include <iostream>
using namespace std;

//Lesson #23 - Integer Format(printf) [ œ—Ì» «÷«›Ì „‰ ÃÌ„Ì 1]
int main()
{
	int Hours = 5, Minutes = 9, Seconds = 1;

	printf("The Time is: %0*d:%0*d:%0*d \n\n", 2, Hours, 2, Minutes, 2, Seconds);

	int TotalItems = 100, Downloaded = 7;

	printf("Progress: [%0*d/%0*d] \n", 3, Downloaded, 3, TotalItems);


	return 0;
}