#include "Bank.h"
#include "Person.h"
using namespace std;

// Constructor for the 'Bank' class.
// It takes the bank name and the maximum size of the bank as input parameters.
Bank::Bank(string name, int size)
{
	this->name = name; // Assign the provided bank name to the 'name' member variable of the class.
	this->size = size; // Assign the provided bank size to the 'size' member variable of the class.
	persons = new Person[size]; // Allocate memory for an array of 'Person' objects with the given 'size'.
}


// Function to resize the 'persons' array to double its current size.
// It takes the current 'persons' array as input and returns a pointer to the newly resized array.
Person* Bank::resize(Person* persons)
{
	// Create a new dynamic array 'temp' with double the size of the current 'persons' array.
	Person* temp = new Person[size * 2];

	// Copy the contents of the current 'persons' array to the newly created 'temp' array.
	for (int i = 0; i < size; i++)
	{
		temp[i] = persons[i];
	}

	// Deallocate memory for the current 'persons' array to prevent memory leaks.
	delete[] persons;

	// Update the 'size' member variable to reflect the new size of the 'persons' array.
	size *= 2;

	// Return the pointer to the newly resized 'temp' array.
	return temp;
}


// Function to check if the 'persons' array is full, and if so, resize it to double its current size.
// This function is called before adding a new person to the 'persons' array to ensure enough space is available.
void Bank::placeCheck()
{
	// Count the number of used slots in the 'persons' array.
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (persons[i].getUsed())
		{
			count++;
		}
	}

	// If the number of used slots is equal to the current size, it means the array is full.
	if (count == size)
	{
		// Call the 'resize' function to double the size of the 'persons' array.
		// This function will create a new array with double the size, copy the contents, 
		// and deallocate the old array.
		persons = resize(persons);
	}
}


// Function to calculate the total balance of all active accounts in the bank.
// It iterates through the 'persons' array and adds the balance of each active account to 'TotalBankBalance'.
int Bank::TotalBankBalance()
{
	// Initialize a variable to store the total bank balance.
	int TotalBankBalance = 0;

	// Iterate through the 'persons' array.
	for (int i = 0; i < size; i++)
	{
		// Check if the slot is used (i.e., an account is present).
		if (persons[i].getUsed())
		{
			// If the slot is used, add the balance of the account to the total bank balance.
			TotalBankBalance += persons[i].getBalance();
		}
	}

	// Return the total bank balance.
	return TotalBankBalance;
}


// Function to set a new Person object in the 'persons' array of the Bank.
// It first checks if there is enough space in the 'persons' array to add a new person.
// If there is not enough space, it resizes the array using 'resize()' method.
// Then, it searches for the first available slot (unused slot) in the 'persons' array.
// Once it finds an unused slot, it assigns the 'person' parameter to that slot.
// It also sets the person's number using 'setNumber()' method and breaks the loop.
void Bank::setPerson(Person person)
{
	// Check if there is enough space in the 'persons' array to add a new person.
	// If not, resize the array using 'resize()' method to accommodate more persons.
	placeCheck();

	// Search for the first available slot (unused slot) in the 'persons' array.
	for (int i = 0; i < size; i++)
	{
		// Check if the current slot is not used (i.e., no person is assigned to it).
		if (!persons[i].getUsed())
		{
			// If the slot is not used, assign the 'person' parameter to that slot.
			persons[i] = person;

			// Set the person's number using the 'setNumber()' method.
			persons[i].setNumber(i);

			// Break the loop since the person is successfully added to the bank.
			break;
		}
	}
}


// Function to edit a Person object in the 'persons' array of the Bank using the person's number.
// It takes the 'number' parameter as the person's identification number.
// It also takes 'name' and 'balance' as references to update the person's name and balance.
// It uses the 'setName()' and 'setBalance()' methods of the Person class to update the values.
void Bank::editPersonByNumber(int number, string& name, int& balance)
{
	// Update the person's name using the 'setName()' method of the Person class.
	persons[number].setName(name);

	// Update the person's balance using the 'setBalance()' method of the Person class.
	persons[number].setBalance(balance);
}


// Function to get a Person object from the 'persons' array of the Bank using the person's number.
// It takes the 'number' parameter as the person's identification number.
// It returns the Person object associated with the given identification number.
Person Bank::getPerson(int number)
{
	// Return the Person object located at the specified 'number' index in the 'persons' array.
	// This allows accessing the details (name, balance, etc.) of the desired person.
	return persons[number];
}


// Function to get the size of the 'persons' array in the Bank object.
// It returns the number of elements (persons) that can be stored in the 'persons' array.
int Bank::getSize()
{
	// Return the current size of the 'persons' array.
	// This indicates the maximum number of persons that the Bank can store.
	return size;
}


// Function to delete a person from the 'persons' array in the Bank object.
// It takes an integer 'number' as input, representing the index of the person to be deleted in the 'persons' array.
void Bank::deletePerson(int number)
{
	// Call the 'deletePerson()' function on the person at the specified index in the 'persons' array.
	persons[number].deletePerson();
}
