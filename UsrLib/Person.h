#pragma once
#include "stdafx.h"
#include <string>
#include "PhysicalAddress.h"
#include "ElectronicAddress.h"

class Person
{
    static UInteger mLifeExpectancy;
protected:
    UInteger ssn;
public:
    const static int    mFemale = 0;
    const static int    mMale = 1;

    string              mFirstName;
    string              mMiddleName;
    string              mLastName;
    UInteger            mAge;
    int                 mSex;
    PhysicalAddress     *mpAddress;
    ElectronicAddress   *mpEAddress;

    Person(string const& firstName, string const& middleName,
        string const& lastName, UInteger age, int sex);
    Person(string const& firstName, string const& middleName,
        string const& lastName, UInteger age, int sex,
        PhysicalAddress const& address, ElectronicAddress const& eAddress);
    Person(const Person& p);
    Person();
    ~Person();

    virtual void greet();

    static UInteger getLifeExpectancy();
};
