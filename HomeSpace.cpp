#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

// [C07] Problem #48: Show All Clients [My Solution]
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

vector <string> ExtractLinesFromFile(const string &ClientsFileName)
{
	vector <string> vLines;

	fstream MyFile;
	MyFile.open(ClientsFileName, ios::in);
	
	if (MyFile.is_open())
	{
		string Line = "";

		while (getline(MyFile, Line))
		{
			vLines.push_back(Line);
		}

		MyFile.close();
	}

	return vLines;
}

vector <stClient> ConvertLinesToRecords(vector <string>& vLines)
{
	vector <stClient> vClients;

	for (string &Line : vLines)
	{
		vClients.push_back(ConvertLineToRecord(Line));
	}

	return vClients;
}

string Tabs(short NumberOfTabs)
{
	string t = "";

	for (int i = 0; i < NumberOfTabs; i++)
	{
		t += "\t";
	}

	return t;
}

void ShowClientListScreen(short ClientNumber)
{
	cout << "\n" << Tabs(4) << "Client List (" << ClientNumber << ") Client(s).\n";
	cout << "____________________________________________________________________________________________\n\n";
	cout << "| Account Number  | Pin Code  | Client Name                       | Phone       | Balance\n";
	cout << "____________________________________________________________________________________________\n\n";
}

void PrintClinetLine(stClient &Client)
{
	cout << "| " << left <<  setw(16) << Client.AccountNumber
		 << "| " << left <<  setw(10) << Client.PinCode
		 << "| " << left <<  setw(34) << Client.Name
		 << "| " << left <<  setw(12) << Client.Phone
		 << "| " << left <<  setw(10) << Client.AccountBalance;
}

void ShowFinalClientScreen(vector <stClient> vClient)
{
	ShowClientListScreen(vClient.size());

	for (stClient& Client : vClient)
	{
		PrintClinetLine(Client);
		cout << endl;
	}

	cout << "____________________________________________________________________________________________\n";
}

void ReadClientsFile(string ClientsFileName)
{
	vector <string> stClientLine = ExtractLinesFromFile(ClientsFileName);

	vector <stClient> stClient = ConvertLinesToRecords(stClientLine);

	ShowFinalClientScreen(stClient);
}


int main()
{
	ReadClientsFile(ClientsFileName);


	system("pause>0");

	return 0;
}