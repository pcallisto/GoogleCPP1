#pragma once

class ElectronicAddress
{
public:
    StringLatin1  mEmail;

    ElectronicAddress();
    //    ElectronicAddress(string const& email) {};
    StringLatin1 GetEAddress() { return mEmail; };
    void SetEAddress(StringLatin1 x) { mEmail = x; };

    ElectronicAddress(StringLatin1 const& email)
        : mEmail(email) {};
    ~ElectronicAddress() {};
};
