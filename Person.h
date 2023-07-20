#pragma once
#include <iostream>
using namespace std;

class Person
{
private:
	string name;      // Private member variable to store the name of the person
	int number;       // Private member variable to store the number of the person
	int balance;      // Private member variable to store the balance of the person
	bool used;        // Private member variable to track if the person is used or not (i.e., if the person is allocated in the Bank)

public:
	// Constructor to initialize the person with a name and balance
	Person(string name, int balance);

	// Default constructor
	Person();

	// Function to check if the person is used (allocated in the Bank)
	bool getUsed();

	// Function to get the balance of the person
	int getBalance();

	// Function to get the name of the person
	string getName();

	// Function to set the number of the person
	void setNumber(int num);

	// Function to set the name of the person
	void setName(string name);

	// Function to set the balance of the person
	void setBalance(int balance);

	// Function to mark the person as unused or unallocated in the Bank
	void deletePerson();
};


