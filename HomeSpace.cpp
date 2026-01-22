#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Lesson #55 - Load Data From File to Vector
void LoadDataFromFileToVector(string FileName, vector <string>& vFileContent)
{
	fstream MyFile;

	MyFile.open(FileName, ios::in); //Read Mode

	if (MyFile.is_open())
	{
		string Line;

		while (getline(MyFile, Line))
		{
			vFileContent.push_back(Line);
		}

		MyFile.close();
	}
}


int main()
{
	vector <string> vFileContenet;

	LoadDataFromFileToVector("MyFile.txt", vFileContenet);

	for (string& Line : vFileContenet)
	{
		cout << Line << endl;
	}


	return 0;
}