#include "Person.h"
using namespace std;

Person::Person() {
	name = "";
	number = -1;
	ballance = 0;
	used = false;

}

Person::Person(string s_name, int s_ballance)
{
	name = s_name;
	ballance = s_ballance;
	used = true;
}


bool Person::getUsed()
{
	return used;
}

int Person::getBallance()
{
	return ballance;
}

string Person::getName()
{
	return name;
}

void Person::setNumber(int s_number)
{
	number = s_number;
}

void Person::setName(string s_name)
{
	name = s_name;
}

void Person::setBalance(int s_ballance)
{
	ballance = s_ballance;
}

void Person::deletePerson()
{
	Person();
}
