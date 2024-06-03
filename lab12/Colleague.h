
#include "Contact.h"
#include <string>
using namespace std;

class Colleague: public Contact {
public: 
    string phone_number;
    string company;
    string adress;
    string tip();
    Colleague(string n, string a, string p, string c)
    {
        this->adress = a;
        this->company = c;
        this->Name = n;
        this->phone_number = p;
    }
};
