#pragma once
#include <string>

class PhysicalAddress
{
public:
    PhysicalAddress();

    PhysicalAddress CreatePhysicalAddress();

    string GetAddress2() { return mAddress2; };
    void SetAddress2(string x) { mAddress2 = x; };
    string GetStreetNum() { return mStreetNum; };
    void SetStreetNum(string x) { mStreetNum = x; };
    string GetStreetName() { return  mStreetName; };
    void SetStreetName(string x) { mStreetName = x; };
    string GetCity() { return  mCity; };
    void SetCity(string x) { mCity = x; };
    string GetProvince() { return  mProvince; };
    void SetProvince(string x) { mProvince = x; };
    string GetCountry() { return  mCountry; };
    void SetCountry(string x) { mCountry = x; };
    string GetPostalCode() { return  mPostalCode; };
    void SetPostalCode(string x) { mPostalCode = x; };

    PhysicalAddress(
        string const& streetNum,
        string const& streetName,
        string const& address2,
        string const& city,
        string const& province,
        string const& country,
        string const& postalCode
    ) :
        mStreetNum(streetNum),
        mStreetName(streetName),
        mAddress2(address2),
        mCity(city),
        mProvince(province),
        mCountry(country),
        mPostalCode(postalCode)
    {}

protected:
    string mStreetNum;
    string mStreetName;
    string mAddress2;
    string mCity;
    string mProvince;
    string mCountry;
    string mPostalCode;
};
