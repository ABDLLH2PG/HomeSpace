#include <iostream>
using namespace std;

//Lesson #24 - Float Format (printf) [ÊÏÑíÈ ãä Ìíãí 1]
int main()
{
	float Grade1 = 95.5, Grade2 = 88.0, Grade3 = 70.25;
	float Average = (Grade1 + Grade2 + Grade3) / 3.0;

	printf("The Average is %.*f \n\n", 3, Average);

	printf("The Average is %.3f \n", Average);



	return 0;
}