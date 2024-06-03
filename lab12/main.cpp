#include <iostream>
#include "AddressBook.h"
#include "Friend.h"
#include "Colleague.h"
#include "Acquaintance.h"
int main()
{
    AddressBook s;
    s.add(new Friend("Giaga", "1.11.2001", "0774748939", "Iasi?")).add(new Friend("Capybara", "31.1.2009", "0744932087", "Roman"));
    s.add(new Acquaintance("Gigel", "2901937302")).add(new Colleague("Leon", "Bucuresti", "3293027189", "ProfTare"));
    s.friends();
    s.search("Capybara");
    s.dele("Giaga");
    printf("\n");
    s.friends();
    return 0;
}
