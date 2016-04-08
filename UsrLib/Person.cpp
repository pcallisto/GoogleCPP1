#pragma once
#include "stdafx.h"
#include <iostream>
#include "Person.h"
#include "PhysicalAddress.h"
#include "ElectronicAddress.h"

using namespace std;

Person::Person(string const& firstName, string const& middleName,
    string const&lastName, UInteger age, int sex)
    : mFirstName(firstName), mMiddleName(middleName),
    mLastName(lastName), mAge(age), mSex(sex)
{
    mpAddress = nullptr;
    mpEAddress = nullptr;
};
Person::Person()
    : mFirstName("_blank"), mMiddleName("_"), mLastName("_blank"),
    mAge(0), mSex(0)
{
    mpAddress = nullptr;
    mpEAddress = nullptr;
};
Person::Person(string const& firstName, string const& middleName,
    string const& lastName, UInteger age, int sex,
    PhysicalAddress const& address, ElectronicAddress const& eAddress)
    : Person(firstName, middleName, lastName, age, sex)
{
    if (mpAddress != nullptr)
        delete mpAddress;
    if (mpEAddress != nullptr)
        delete mpEAddress;

    mpAddress = new PhysicalAddress(address);
    mpEAddress = new ElectronicAddress(eAddress);
};

Person::Person(Person const& p)
    : mFirstName(p.mFirstName), mMiddleName(p.mMiddleName),
    mLastName(p.mLastName), mAge(p.mAge)
{
    auto* a = p.mpAddress;
    mpAddress = new PhysicalAddress(a->GetStreetNum(), a->GetStreetName(),
        a->GetAddress2(), a->GetCity(), a->GetProvince(), a->GetCountry(),
        a->GetPostalCode());

    auto* b = p.mpEAddress;
    mpEAddress = new ElectronicAddress(b->GetEAddress());
}

Person::~Person()
{
    if (mpAddress != nullptr)
    {
        delete mpAddress;
        mpAddress = nullptr;
    }
    if (mpEAddress != nullptr)
    {
        delete mpEAddress;
        mpEAddress = nullptr;
    }
}

void Person::greet()
{
    cout << "My name is " << mFirstName << " " << mLastName <<
        " and I am " << mAge << " years old." << endl;

    if (mpAddress)
    {
        cout << "I live at " <<
            mpAddress->GetStreetNum() << " "
            << mpAddress->GetStreetName() <<
            ", " << mpAddress->GetCity() << endl;
    }

    if (mpEAddress)
    {
        cout << "and my email address is <" <<
            mpEAddress->GetEAddress() << ">." << endl;
    }
}

UInteger Person::getLifeExpectancy()
{
    return mLifeExpectancy;
}

UInteger Person::mLifeExpectancy = 80;