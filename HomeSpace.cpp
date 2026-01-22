#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Lesson #56 - Save Vector to File
void SaveVectorToFile(string FileName, vector <string> vFileContent)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out);

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


int main()
{
	vector <string> vFileContenet{ "Ali", "Shadi", "Maher", "Fadi", "Lama" };

	SaveVectorToFile("MyFile.txt", vFileContenet);

	return 0;
}