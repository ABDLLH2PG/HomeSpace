#include <iostream>
using namespace std;

//Lesson #25 - String and Char Format(printf) [ÊÏÑíÈ ãä Ìíãí 2]
int main()
{
	char star = '*';

	printf("%*c \n", 1, star);
	printf("%*c \n", 2, star);
	printf("%*c \n", 3, star);
	printf("%*c \n", 4, star);

	return 0;
}