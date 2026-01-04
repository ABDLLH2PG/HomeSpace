#include <iostream>
using namespace std;

//Lesson #24 - Float Format (printf) [ œ—Ì» „‰ ÃÌ„Ì 2]
int main()
{
	double DollarToRiyal = 3.7512345;

	printf("Price (Low Precision): %.1f \n\n", DollarToRiyal);

	printf("Price (High Precision): %.*f \n", 5, DollarToRiyal);


	return 0;
}