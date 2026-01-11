#include <iostream>
#include <vector>
using namespace std;
// Lesson # 30 - Vector of Structure [HomeWork]
struct stEmployee
{
	string FirstName;
	string LastName;
	float Salary;
};

void ReadEmployees(vector <stEmployee> & vEmployees)
{
	char ReadMore = 'Y';
	stEmployee tempEmployee;

	do
	{
		cout << "Please enter FirstName? ";
		cin >> tempEmployee.FirstName;

		cout << "Please enter Lastname? ";
		cin >> tempEmployee.LastName;

		cout << "Please enter Salary? ";
		cin >> tempEmployee.Salary;

		vEmployees.push_back(tempEmployee);

		cout << "\nDo you want to read more employees ? Y/N ? ";
		cin >> ReadMore;

	} while (ReadMore == 'Y' || ReadMore == 'y');

}

void PrintEmployees(vector <stEmployee> & vEmployees)
{
	cout << "\nEmployees Vector: \n\n";

	//ranged loop
	for (stEmployee &Employee : vEmployees)
	{
		cout << "FirstName: " << Employee.FirstName << endl;
		cout << "LastName : " << Employee.LastName << endl;
		cout << "Salary   : " << Employee.Salary << endl;
		cout << endl;
	}
}


int main()
{
	vector <stEmployee> vEmployees;

	ReadEmployees(vEmployees);
	PrintEmployees(vEmployees);


	return 0;
}