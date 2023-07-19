#include "Bank.h"
#include "Person.h"
using namespace std;

Bank::Bank(string s_name, int s_clients_size)
{
	name = s_name;
	persons = new Person[s_clients_size];
	size = s_clients_size;
}

void Bank::resize(Person* persons)
{
	Person* temp = new Person[size * 2];

	for (int i = 0; i < size; i++)
	{
		temp[i] = persons[i];
	}
	delete[] persons;
	persons = temp;

	size *= 2;
}

void Bank::placeCheck(Person* persons)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (persons[i].getUsed())
		{
			count++;
		}
	}

	if (count == size)
	{
		resize(persons);
	}
}

//int Bank::TotalBankBalance()
//{
//	int TotalBankBalance = 0;
//	for (int i = 0; i < size; i++)
//	{
//		if (persons[i].getUsed())
//		{
//			TotalBankBalance += persons[i].getBallance();
//		}
//	}
//}

void Bank::setPerson(Person person)
{
	placeCheck(persons);

	for (int i = 0; i < size; i++)
	{
		if (!persons[i].getUsed())
		{
			persons[i] = person;
			persons[i].setNumber(i);
			break;
		}
	}
}

void Bank::editPersonByNumber(int number, string& name, int& ballance)
{
	persons[number].setName(name);
	persons[number].setBalance(ballance);
}

void Bank::getPerson(int number, string& name, int& ballance, bool& used)
{
	name = persons[number].getName();
	ballance = persons[number].getBallance();
	used = persons[number].getUsed();
}

void Bank::deletePerson(int number)
{
	persons[number].deletePerson();
}
