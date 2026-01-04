#include <iostream>
using namespace std;

//Lesson #23 - Integer Format(printf) [ œ—Ì» «÷«›Ì „‰ ÃÌ„Ì 2]
int main()
{
	int Price = 50, Quantity = 3;

	printf("Price: %d, Qty: %d, Total: %0*d \n", Price, Quantity, 4, Price * Quantity);


	return 0;
}