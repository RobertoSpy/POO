#include "AddressBook.h"
using namespace std;

AddressBook& AddressBook::add(Contact* x) 
{
	this->contacts[length] = x;
	length++;
	return (*this);
}

AddressBook& AddressBook::dele(string name)
{
	for (int i = 0; i < length; i++)
	{
		if (this->contacts[i]->Name == name)
		{
			Contact* x = this->contacts[i];
			for (int j = i; j < length - 1; j++)
				this->contacts[j] = this->contacts[j + 1];
			length--;
			delete x;
			break;
		}
	}
	return (*this);
}
void AddressBook::friends()
{
	string test = "Friend";
	for (int i = 0; i < length; i++)
		if (this->contacts[i]->tip() == test)
			cout << this->contacts[i]->Name << endl;
}
Contact& AddressBook::search(string name)
{
	for (int i = 0; i < length; i++)
		if (this->contacts[i]->Name == name)
			return (*contacts[i]);
	cout << "Nu am gasit contactul" << endl;
}