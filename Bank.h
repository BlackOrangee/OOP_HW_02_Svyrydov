#pragma once
#include <iostream>
#include "Person.h"

using namespace std;

class Bank
{
private:
	string name;
	int total_balance;
	int size = 5;
	
	Person* persons = nullptr;

	Person* resize(Person* persons);
	void placeCheck(Person* persons);
	
public:

	

	int getSize();

	void getPerson(int number, string& name, int& ballance, bool& used);

	//int TotalBankBalance();

	Bank(string s_name, int s_clients_size);
	
	//void setPerson(Person person);

	//void editPersonByNumber(int number, string& name, int& ballance);

	void deletePerson(int number);
};