// Create a Bank class that contains private fields for the bank name, customer list, and total bank balance.
// The Customer class must have private fields for the customer's name, account, and balance.
// Add public methods to the Bank class to add a new customer, remove a customer, deposit, 
// and withdraw funds from a customer's account.
// Write code that creates an object of the Bank class, adds several customers, 
// performs depositand withdrawal operations, and displays each customer's balance and the total bank balance.
//

#include <iostream>
#include "Bank.h"
using namespace std;

// EditMenu function allows the user to choose between editing the name or balance of a client.
// It takes two parameters by reference: 'name' (string) and 'balance' (int) of the client.
void EditMenu(string& name, int& balance)
{
	int menu = 0;
	cout << "\n\n\t1 -- Edit name\n\t2 -- Edit balance\n\t"; cin >> menu;

	// If the user chooses to edit the name (menu == 1)
	if (menu == 1)
	{
		cout << "\n\n\tEnter new name: "; cin >> name; // Prompt the user to enter a new name for the client.
	}
	// If the user chooses to edit the balance (menu == 2)
	else if (menu == 2)
	{
		cout << "\n\n\tEnter new balance: "; cin >> balance; // Prompt the user to enter a new balance for the client.
	}
	else // If an invalid option is selected, repeat the EditMenu until a valid option is chosen.
	{
		EditMenu(name, balance);
	}
}


// Edit function allows the user to edit the details of a client in the bank.
// It takes the 'bank' object as a parameter to perform the edit operations.
void Edit(Bank& bank)
{
	int number = 0;

	cout << "\n\n\tEnter client number: ";	cin >> number; // Prompt the user to enter the client number.

	Person person = bank.getPerson(number); // Retrieve the client's details using the client number.

	string name = person.getName(); // Get the current name of the client.
	int balance = person.getBalance(); // Get the current balance of the client.

	// Display the current details of the client.
	cout << "\n\n\tClient name: " << name << "\n\tClient balance: " << balance;

	// Call the EditMenu function to allow the user to choose between editing the name or balance.
	EditMenu(name, balance);

	// Update the client's details in the bank with the edited name and balance.
	bank.editPersonByNumber(number, name, balance);
}


// Delete function allows the user to delete a client from the bank.
// It takes the 'bank' object as a parameter to perform the delete operation.
void Delete(Bank& bank)
{
	int number = 0;
	cout << "\n\n\tEnter client number: ";	cin >> number; // Prompt the user to enter the client number to be deleted.
	bank.deletePerson(number); // Call the deletePerson function of the bank object to remove the client with the specified number.
}


// Add function allows the user to add a new client to the bank.
// It takes the 'bank' object as a parameter to perform the add operation.
void Add(Bank& bank)
{
	string name;
	int balance;

	cout << "\n\n\tAdd person menu\n\n\tName: "; cin >> name; // Prompt the user to enter the name of the new client.
	cout << "\n\tBalance: "; cin >> balance; // Prompt the user to enter the initial balance of the new client.

	Person person(name, balance); // Create a new Person object with the provided name and balance.

	bank.setPerson(person); // Call the setPerson function of the bank object to add the new client to the bank.
}


// Print function displays the details of all active clients in the bank.
// It takes the 'bank' object as a parameter to access the client information.
void Print(Bank& bank)
{
	Person person; // Create a Person object to store the client details.

	for (int i = 0; i < bank.getSize(); i++) // Loop through all the client slots in the bank.
	{
		person = bank.getPerson(i); // Get the client information stored in the 'i'-th slot.

		if (person.getUsed()) // Check if the slot is occupied by an active client.
		{
			// Display the client details: client number, name, and balance.
			cout << "\n\n\n\tClient number: " << i
				<< "\n\tName: " << person.getName()
				<< "\n\tBalance: " << person.getBalance();
		}
	}

	
	// Call the TotalBankBalance function of the 'bank' object to display the total balance of all clients in the bank.
	cout << "\n\n\tTotal bank balance: " << bank.TotalBankBalance();
}


// Menu function displays the main menu for interacting with the bank's clients.
// It takes the 'bank' object as a parameter to perform operations on clients.
void Menu(Bank& bank)
{
	int menu = 0; // Variable to store the user's menu choice.

	do
	{
		// Display the main menu options to the user.
		cout << "\n\n\t1 -- Add\n\t2 -- Delete\n\t3 -- Edit\n\t4 -- Print\n\t";
		cin >> menu; // Get the user's menu choice.

		switch (menu) // Based on the user's choice, perform corresponding operations.
		{
		case 1:
			Add(bank); // Call the 'Add' function to add a new client to the bank.
			break;
		case 2:
			Delete(bank); // Call the 'Delete' function to remove a client from the bank.
			break;
		case 3:
			Edit(bank); // Call the 'Edit' function to edit details of an existing client.
			break;
		case 4:
			Print(bank); // Call the 'Print' function to display details of all active clients.
			break;
		default:
			break;
		}
	} while (true); // Repeat the menu display until the user decides to exit the program (no break condition).
}


int main()
{
	string name; // Variable to store the name of the bank.
	cout << "\n\n\tBank name: ";
	cin >> name; // Get the name of the bank from the user.

	int size; // Variable to store the size of the bank (number of clients).
	cout << "\n\tEnter size: ";
	cin >> size; // Get the size of the bank from the user.

	// Create a 'Bank' object named 'bank' with the given name and size.
	Bank bank(name, size);

	// Call the 'Menu' function to display the main menu and interact with the bank's clients.
	Menu(bank);
}
