#include "Person.h"
using namespace std;

// Default constructor for the Person class
Person::Person()
{
	// Initialize the person with default values
	name = "";       // Empty string for the name
	number = -1;     // -1 for the number (indicating it is not assigned yet)
	balance = 0;     // 0 for the initial balance
	used = false;    // Flag set to false, indicating the person is not used or allocated in the Bank
}


// Constructor for the Person class that takes name and balance as parameters
Person::Person(string name, int balance)
{
	// Set the member variables using the provided parameters
	this->name = name;        // Set the name to the provided name
	this->balance = balance;  // Set the balance to the provided balance
	used = true;              // Mark the person as used or allocated in the Bank
}


// Function to get the 'used' status of the Person object
bool Person::getUsed()
{
	// Return the value of the 'used' member variable
	return used;
}


// Function to get the balance of the Person object
int Person::getBalance()
{
	// Return the value of the 'balance' member variable
	return balance;
}


// Function to get the name of the Person object
string Person::getName()
{
	// Return the value of the 'name' member variable
	return name;
}


// Function to set the number of the Person object
void Person::setNumber(int number)
{
	// Set the 'number' member variable to the provided 'number' value
	this->number = number;
}

// Function to set the name of the Person object
void Person::setName(string name)
{
	// Set the 'name' member variable to the provided 'name' value
	this->name = name;
}

// Function to set the balance of the Person object
void Person::setBalance(int balance)
{
	// Set the 'balance' member variable to the provided 'balance' value
	this->balance = balance;
}

// Function to "delete" the Person object
void Person::deletePerson()
{
	// Create a new Person object with default values to effectively "delete" the current object
	Person();
}

