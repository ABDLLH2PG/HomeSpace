#include <iostream>
#include <vector>
using namespace std;

//Lesson #29 - Add elements [Al HomeWork]
void ReadNumbers(vector <int> & vNumbers)
{
	char ReadMore = 'Y';
	int Number = 0;

	do
	{
		cout << "Please enter a number ? ";
		cin >> Number;

		vNumbers.push_back(Number);

		cout << "\nDo you want to add more numbers ? Y/N ? ";
		cin >> ReadMore;

	} while (ReadMore == 'Y' || ReadMore == 'y');

}

int SumVectorNumbers(vector <int> & vNumbers)
{
	int Sum = 0;

	for (int Number : vNumbers)
	{
		Sum += Number;
	}

	return Sum;
}

int MaxNumber(vector <int> & vNumbers)
{
	int Max = vNumbers[0];

	for (int Number : vNumbers)
	{
		if (Number > Max)
		{
			Max = Number;
		}
	}

	return Max;
}

void PrintVectorNumbers(vector <int> & vNumbers)
{
	for (int i = 0; i < vNumbers.size(); i++)
	{
		cout << vNumbers[i];

		if (i < vNumbers.size() - 1)
		{
			cout << ", ";
		}
	}

	cout << endl;
}


int main()
{
	vector <int> vNumbers;

	ReadNumbers(vNumbers);

	cout << "\nNumbers Vector: ";
	PrintVectorNumbers(vNumbers);

	cout << "Total Sum: " << SumVectorNumbers(vNumbers) << endl;

	cout << "Maximum Number: " << MaxNumber(vNumbers) << endl;


	return 0;
}