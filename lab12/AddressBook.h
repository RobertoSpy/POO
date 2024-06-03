
#include "Contact.h"
#include <iostream>
#include <string>
using namespace std;
class AddressBook 
{
public: 
    Contact** contacts;
    int length;
    
Contact& search(string name);
    
AddressBook& dele(string name);
    
AddressBook& add(Contact* x);
    
void friends();

AddressBook()
{
    length = 0;
    contacts = new Contact * [100];
}
~AddressBook()
{
    for (int i = 0; i < length; i++)
        delete contacts[i];
    delete[] contacts;
}
};
