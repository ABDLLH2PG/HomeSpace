#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Lesson #54 - Read Mode: Print file Content
void PrintFileContenet(string FileName)
{
	fstream MyFile;

	MyFile.open(FileName, ios::in); //Read Mode

	if (MyFile.is_open())
	{
		string Line;

		while (getline(MyFile, Line))
		{
			cout << Line << endl;
		}

		MyFile.close();
	}
}


int main()
{
	PrintFileContenet("MyFile.txt");



	return 0;
}