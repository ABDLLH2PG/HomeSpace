#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "MyInputLib.h"

// [C07] Problem #50: Delete Client By Account Number [My Solution]
using namespace std;

const string ClientsFileName = "Clients.txt";

struct stClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0.0;
};

vector <string> SplitString(string S1, string Delim = " ")
{
	vector <string> vString;

	short pos = 0;
	string sWord;

	while ((pos = S1.find(Delim)) != string::npos)
	{
		sWord = S1.substr(0, pos);

		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		S1.erase(0, pos + Delim.length());
	}

	if (S1 != "")
	{
		vString.push_back(S1);
	}

	return vString;
}

stClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
	stClient Client;

	vector <string> vClientData;
	vClientData = SplitString(Line, Seperator);

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]); //cast string to double

	return Client;
}

vector <stClient> LoadClientsDataFromFile(string FileName)
{
	vector <stClient> vClients;

	fstream MyFile;
	MyFile.open(FileName, ios::in); //read Mode

	if (MyFile.is_open())
	{
		string Line;
		stClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);

			vClients.push_back(Client);
		}

		MyFile.close();
	}

	return vClients;
}

void PrintClientCard(stClient Client)
{
	cout << "\nThe following are the Client details:\n";

	cout << "\nAccount Number: " << Client.AccountNumber;
	cout << "\nPin Code      : " << Client.PinCode;
	cout << "\nName          : " << Client.Name;
	cout << "\nPhone         : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
}

bool FindClientByAccountNumber(string AccountNumber, stClient& Client)
{
	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	for (stClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

void DeleteClientFromFile(stClient& Client)
{
	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	for (stClient& C : vClients)
	{
		if (C.AccountNumber == Client.AccountNumber)
		{
			C.AccountNumber = "";
			C.PinCode = "";
			C.Name = "";
			C.Phone = "";
			C.AccountBalance = 0.0;
		}
	}
}

void AskToDeleteClientFromFile(stClient& Client)
{
	char DeleteClient = MyInputLib::ReadChar("\nAre you sure you want delete this client? y/n ? ");

	if (tolower(DeleteClient) == 'y')
	{
		DeleteClientFromFile(Client);
		cout << "\n\nClient Deleted Successfully.";
	}
}

int main()
{
	stClient Client;
	string AccountNumber = MyInputLib::ReadString("Please enter Account Number? ");

	if (FindClientByAccountNumber(AccountNumber, Client))
	{
		PrintClientCard(Client);
		AskToDeleteClientFromFile(Client);
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
	}
	
	
	system("pause>0");

	return 0;
}