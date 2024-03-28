#include "Number.h"
#include <iostream>

using namespace std;

int main()
{
	Number n1("121", 3);
	Number n2("734", 8);
	Number n3("345", 6);
	n2.Print();
	n2--;
	n2.Print();
	--n2;
	n2.Print();
	n1 = n2+n3;
	n1.Print();
	
	
}