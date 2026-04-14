#include <iostream>
#include <string>
#include <vector>

// [C07] Problem #46: Convert Line Data to Record [My Solution]
using namespace std;

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

stClient ConvertvRecordLineToStruct(vector <string> &vRecordLine)
{
	stClient Client;

	Client.AccountNumber = vRecordLine[0];
	Client.PinCode = vRecordLine[1];
	Client.Name = vRecordLine[2];
	Client.Phone = vRecordLine[3];
	Client.AccountBalance = stod(vRecordLine[4]);

	return Client;
}

void PrintClientData(stClient Client)
{
	cout << "Account Number : " << Client.AccountNumber << "\n";
	cout << "Pin Code       : " << Client.PinCode << "\n";
	cout << "Name           : " << Client.Name << "\n";
	cout << "Phone          : " << Client.Phone << "\n";
	cout << "Account Balance: " << Client.AccountBalance;
}


int main()
{
	stClient Client;

	string S1 = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";

	cout << "\nLine Record is:\n";
	cout << S1;

	vector <string> vRecordLine = SplitString(S1, "#//#");

	Client = ConvertvRecordLineToStruct(vRecordLine);

	cout << "\n\nThe following is teh extracted client record:\n\n";

	PrintClientData(Client);
	

	system("pause>0");

	return 0;
}