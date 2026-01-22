#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>

using namespace std;

// Datatime: Local/UTC Time
int main()
{
	time_t t = time(0); // get time now

	char* dt = ctime(&t); // convert in string form
	cout << "Local data and time is: " << dt << "\n";

	tm* gmtm = gmtime(&t); // converting now to tm struct for UTC data/time
	dt = asctime(gmtm);
	cout << "UTC data and time is: " << dt;


	return 0;
}