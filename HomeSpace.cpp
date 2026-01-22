#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Lesson #58 - Update Record In File
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

void SaveVectorToFile(string FileName, vector <string> vFileContent)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out); //Write Mode

	if (MyFile.is_open())
	{
		for (string& Line : vFileContent)
		{
			if (Line != "")
			{
				MyFile << Line << endl;
			}
		}

		MyFile.close();
	}
}

void UpdateRecordInFile(string FileName, string Record, string UpdateTo)
{
	vector <string> vFileContent;

	LoadDataFromFileToVector(FileName, vFileContent);

	for (string& Line : vFileContent)
	{
		if (Line == Record)
		{
			Line == UpdateTo;
		}
	}

	SaveVectorToFile(FileName, vFileContent);
}

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
	cout << "File Content Before Delete:\n";
	PrintFileContenet("MyFile.txt");

	UpdateRecordInFile("MyFile.txt", "Ali", "Omer");

	cout << "\n\nFile Content After Delete:\n";
	PrintFileContenet("MyFile.txt");

	return 0;
}