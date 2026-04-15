#include <iostream>
#include <string>
#include <fstream>

// [C07] Problem #47: Add Clients to File [My Solution]
using namespace std;

struct stClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0.0;
};

stClient ReadNewClient()
{
	stClient Client;

	cout << "Enter Account Number? ";
	getline(cin >> ws, Client.AccountNumber);
	cout << "Enter PinCode? ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin >> ws, Client.Name);

	cout << "Enter Phone? ";
	getline(cin >> ws, Client.Phone);

	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;
}

void AddRecordToFile(string stClient, string FileName)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << stClient << endl;
	}

	MyFile.close();

	cout << "\nClient Added Successfully, ";
}

void AddClientToFile()
{
	char AddClientAgain = 'Y';

	do
	{
		system("cls");
		cout << "Adding New Client:\n\n";

		stClient Client = ReadNewClient();

		string stClientRecord = ConvertRecordToLine(Client, "#//#");

		AddRecordToFile(stClientRecord, "ClientRecord.txt");
		
		cout << "do you want to add more clients? ";
		cin >> AddClientAgain;


	} while (AddClientAgain == 'Y' || AddClientAgain == 'y');
}


int main()
{
	AddClientToFile();


	system("pause>0");

	return 0;
}