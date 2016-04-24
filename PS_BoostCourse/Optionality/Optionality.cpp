#include "stdafx.h"
#include <iostream>

class Address
{
public:
    Address(string streetName) : streetName(streetName) {}
    string streetName;
};

class Person
{
public:
    Person(string firstName, string lastName) :
        firstName(firstName), lastName(lastName) {}

    optional<string> GetName() { return middleName; }

    string firstName, lastName;
    optional<string> middleName;
    optional<Address> address;
};

int main(int argc, char* argv[])
{
    Person p{ "John", "Watson" };

    p.middleName = "Hamish";
    p.middleName = "The Gambler";

    if (p.middleName)
    {
        cout << *p.middleName << endl;
    }

    p.address = Address{ "Baker st." };

    if (p.address)
    {
        cout << p.address->streetName << endl;
    }

    getchar();
    return 0;
}