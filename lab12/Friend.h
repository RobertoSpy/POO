
#include "Contact.h"
#include <string>
using namespace std;


class Friend: public Contact 
{
public: 
    string date_of_birth;
    string phone_number;
    string address;
    string tip();
    Friend(string n, string d, string p, string a)
    {
        this->address = a;
        this->date_of_birth = d;
        this->Name = n;
        this->phone_number = p;
    }
};