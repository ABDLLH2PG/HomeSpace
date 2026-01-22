#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Lesson #54 - Read Mode: Print file Content [AI HomeWork]
void PrintFileContenetWithStudentCounter(string FileName)
{
	fstream MyFile;

	MyFile.open(FileName, ios::in); //Read Mode

	if (MyFile.is_open())
	{
		string Line;
		short Counter = 0;

		while (getline(MyFile, Line))
		{
			Counter++;
			cout << "Student #" << Counter << ": " << Line << endl;
		}

		cout << "\nTotal number of students is: " << Counter << endl;

		MyFile.close();
	}
}

int main()
{
	PrintFileContenetWithStudentCounter("Names.txt");


	return 0;
}