#include <iostream>
#include <string>
#include "MyInputLib.h"

// [C07] Problem #44: Convert Record to Line [My Solution]
using namespace std;

struct stClientData
{
	string AccountNumber = "";
	int PinCode = 0;
	string Name = "";
	long int Phone = 0;
	float AccountBalance = 0.0;
};

string JoinDataByStruct(stClientData& ClientData, string Delim)
{
	string S1 = "";

	S1 += ClientData.AccountNumber + Delim;
	S1 += to_string(ClientData.PinCode) + Delim;
	S1 += ClientData.Name + Delim;
	S1 += to_string(ClientData.Phone) + Delim;
	S1 += to_string(ClientData.AccountBalance) + Delim;

	return S1.substr(0, S1.length() - Delim.length());
}

int main()
{
	stClientData ClientData;

	cout << "Please Enter Client Data:\n\n";

	ClientData.AccountNumber = MyInputLib::ReadString("Enter Account Number? ");
	ClientData.PinCode = MyInputLib::ReadNumber("Enter PinCode? ");
	ClientData.Name = MyInputLib::ReadString("Enter Name? ");
	ClientData.Phone = MyInputLib::ReadNumber("Enter Phone? ");
	ClientData.AccountBalance = MyInputLib::ReadDoubleNumber("Enter AccountBalance? ");

	cout << "\n\nClient Record for Saving is:\n";
	cout << JoinDataByStruct(ClientData, "#//#");


	system("pause>0");

	return 0;
}