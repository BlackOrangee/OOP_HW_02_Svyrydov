//
//

#include <iostream>
#include "Bank.h"
using namespace std;


void EditMenu(string& name, int& ballance)
{
	int menu = 0;
	cout << "\n\n\t1 -- Edit name\n\t2 -- Edit balance\n\t"; cin >> menu;

	if (menu == 1)
	{
		cout << "\n\n\tEnter new name: "; cin >> name;
	}
	else if (menu == 2)
	{
		cout << "\n\n\tEnter new balance: "; cin >> ballance;
	}
	else
	{
		EditMenu(name, ballance);
	}
}

void Edit(Bank& bank)
{
	int number = 0;
	string name;
	int balance = 0;
	bool used = false;

	cout << "\n\n\tEnter client number: ";	cin >> number;

	bank.getPerson(number, name, balance, used);

	cout << "\n\n\tClient name: " << name << "\n\tClient balance: " << balance;

	EditMenu(name, balance);

	bank.editPersonByNumber(number, name, balance);
}

void Delete(Bank& bank)
{
	int number = 0;
	cout << "\n\n\tEnter client number: ";	cin >> number;
	bank.deletePerson(number);
}

void Add(Bank& bank)
{
	string name;
	int ballance;

	cout << "\n\n\tAdd person menu\n\n\tName: "; cin >> name;
	cout << "\n\tBalance: "; cin >> ballance;

	Person person(name, ballance);

	bank.setPerson(person);
}

void Print(Bank& bank)
{
	string name;
	int balance = 0;
	bool used = false;

	for (int i = 0; i < bank.getSize(); i++)
	{
		bank.getPerson(i, name, balance, used);

		if (used)
		{
			cout << "\n\n\n\tClient number: " << i 
				<< "\n\tName: " << name 
				<< "\n\tBalance: " << balance;
		}
	}

	//cout << "\n\n\tTotal bank balance: " << bank.TotalBankBalance();
}

void Menu(Bank& bank)
{
	int menu = 0;
	do
	{
		cout << "\n\n\t1 -- Add\n\t2 -- Delete\n\t3 -- Edit\n\t4 -- Print\n\t"; cin >> menu;

		switch (menu)
		{
		case 1:
			Add(bank);
			break;
		case 2:
			Delete(bank);
			break;
		case 3:
			Edit(bank);
			break;
		case 4:
			Print(bank);
			break;
		default:
			break;
		}
	} while (true);
}

int main()
{
	string name;
	cout << "\n\n\tBank name: ";
	cin >> name;

	int size;
	cout << "\n\tEnter size: ";
	cin >> size;
	Bank bank(name, size);

	Menu(bank);


}