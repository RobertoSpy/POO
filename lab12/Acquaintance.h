
#include "Contact.h"
#include <string>
using namespace std;

class Acquaintance: public Contact {
public: 
    string phone_number;
    string tip();
    Acquaintance(string n, string p)
    {
        this->Name = n;
        this->phone_number = p;
    }
};
