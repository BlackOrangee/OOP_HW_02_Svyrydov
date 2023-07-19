#pragma once
#include <iostream>
using namespace std;

class Person
{
private:
	string name;
	int number;
	int ballance;
	bool used;


public:

	Person(string s_name, int s_ballance);

	Person();

	bool getUsed();
	
	int getBallance();

	string getName();

	void setNumber(int s_number);

	void setName(string s_name);

	void setBalance(int s_ballance);

	void deletePerson();
};

