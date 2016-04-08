#pragma once
#include <iostream>
#include "Person.h"

class Employee : public Person
{
    int mTaxId;
public:
    Employee();
    Employee(string const& firstName, string const& middleName,
        string const& lastName, UInteger age, int sex,
        PhysicalAddress const& address,
        ElectronicAddress const& eAddress,
        string department = { "da MailingRoom" })
        : Person(firstName, middleName, lastName,
            age, sex, address, eAddress),
        mDepartment(department)
    {}
    Employee(string const& firstName, string const& middleName,
        string const& lastName, UInteger age, int sex)

        : Person(firstName, middleName, lastName,
            age, sex),
        mDepartment("_blank")
    {}

    string mDepartment;

    void greet() override;
};
