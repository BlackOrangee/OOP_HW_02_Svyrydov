#pragma once
#include <iostream>
#include "Person.h"

using namespace std;
class Bank
{
private:
	string name;		// Variable to store the name of the bank.
	int total_balance;	// Total balance of all clients in the bank.
	int size;			// Maximum size of the bank (maximum number of clients).

	// Pointer to an array of 'Person' objects (clients).
	Person* persons = nullptr; 

	// Helper function to resize the array of 'Person' objects.
	Person* resize(Person*); 

	// Helper function to check if there is a free slot in the array.
	void placeCheck(); 

public:
	// Constructor for the 'Bank' class.
	Bank(string, int);

	// Function to get the current number of clients in the bank.
	int getSize(); 

	// Function to get a specific client by their index in the array.
	Person getPerson(int); 

	// Function to calculate the total balance of all clients in the bank.
	int TotalBankBalance(); 

	// Function to add a new client to the bank.
	void setPerson(Person); 

	// Function to edit the details of a specific client.
	void editPersonByNumber(int, string&, int&); 

	// Function to delete a client from the bank.
	void deletePerson(int); 
};
