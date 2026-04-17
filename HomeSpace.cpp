#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "MyInputLib.h"

// [C07] Problem #51: Updata Client By Account Number [My Solution]
using namespace std;

const string ClientsFileName = "Clients.txt";

struct stClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0.0;
	bool MarkForDelete = false;
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

bool FindClientByAccountNumber(string AccountNumber, vector <stClient> vClients, stClient& Client)
{
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

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <stClient>& vClients)
{
	for (stClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}
	}
	return false;
}

vector <stClient> SaveClientsDataToFile(string FileName, vector <stClient> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out); //overWrite

	string DataLine;

	if (MyFile.is_open())
	{
		for (stClient C : vClients)
		{
			if (C.MarkForDelete == false)
			{
				// we only write records that are not marked for delete.
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}

		MyFile.close();
	}
	return vClients;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector <stClient>& vClients)
{
	stClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

		cout << "\n\nAre you sure you want delete this client? y/n ? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
			SaveClientsDataToFile(ClientsFileName, vClients);

			//Refresh Clients
			vClients = LoadClientsDataFromFile(ClientsFileName);

			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}
}

stClient UpdateClient()
{
	stClient Client;

	// Usage of std::we will extract all the witespace character
	cout << "Enter PinCode? ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;

	return Client;
}

bool AskClientForUpdateByAccountNumber(string AccountNumber, vector <stClient> &vClients)
{
	stClient Client;
	Client = UpdateClient();

	for (stClient &C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.PinCode = Client.PinCode;
			C.Name = Client.Name;
			C.Phone = Client.Phone;
			C.AccountBalance = Client.AccountBalance;
			return true;
		}
	}
	return false;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector <stClient>& vClients)
{
	stClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

		cout << "\n\nAre you sure you want update this client? y/n ? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			cout << "\n\n";
			AskClientForUpdateByAccountNumber(AccountNumber, vClients);
			SaveClientsDataToFile(ClientsFileName, vClients);

			//Refresh Clients
			vClients = LoadClientsDataFromFile(ClientsFileName);

			cout << "\n\nClient Update Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}
}

int main()
{
	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = MyInputLib::ReadString("Please enter Account Number? ");
	
	UpdateClientByAccountNumber(AccountNumber, vClients);


	system("pause>0");

	return 0;
}