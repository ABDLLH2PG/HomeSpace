#include <iostream>
#include <fstream>
using namespace std;

// Lesson #53 - Append Mode: Append Data to File
int main()
{
	fstream MyFile;

	MyFile.open("MyFile.txt", ios::out | ios::app); //append Mode

	if (MyFile.is_open())
	{
		MyFile << "My name is Abdullah\n";
		MyFile << "I have 19 Years old\n";
		MyFile << "I love ProgrammingAdvice\n";


		MyFile.close();
	}


	
	return 0;
}