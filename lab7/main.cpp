#include <iostream>
#include "dictionar.h"

using namespace std;

int main() 
{
    
    Dictionar<string, string> dict;
    dict["Ana"] = "Maria";
    dict["Gabriela"] = "Vasile";

    cout << dict["Ana"] << endl;
    cout << dict["Gabriela"] << endl;

    return 0;
}
