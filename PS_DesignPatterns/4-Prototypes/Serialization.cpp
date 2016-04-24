#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <sstream>
using namespace std;
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

class gps_position
{
public:
    int degrees;
    int minutes;
    float seconds;
    gps_position() {};
    gps_position(int d, int m, float s) :
        degrees(d), minutes(m), seconds(s)
    {}
};

class bus_stop
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & latitude;
        ar & longitude;
    }
    gps_position latitude;
    gps_position longitude;
protected:
    bus_stop(const gps_position & lat_, const gps_position & long_) :
        latitude(lat_), longitude(long_)
    {}
public:
    bus_stop() {}
    // See item # 14 in Effective C++ by Scott Meyers.
    // re non-virtual destructors in base classes.
    virtual ~bus_stop() {}
};

struct Address
{
    string street, city;
    int suite;

    friend ostream& operator<<(ostream& os, const Address& obj)
    {
        return os
            << "street: " << obj.street
            << " city: " << obj.city
            << " suite: " << obj.suite;
    }

private:
    friend class boost::serialization::access;

    template<class Ar> void serialize(Ar& ar, const unsigned int version)
    {
        ar & street;
        ar & city;
        ar & suite;
    }
};

struct Contact
{
    string name;
    Address* address;

    friend ostream& operator<<(ostream& os, const Contact& obj)
    {
        return os
            << "name: " << obj.name
            << " address: " << *obj.address;
    }
private:
    friend class boost::serialization::access;

    template<class Ar> void serialize(Ar& ar, const unsigned int version)
    {
        ar & name;
        ar & address;
    }
};

int main___()
{
    Contact john;
    john.name = "John Doe";
    john.address = new Address{ "123 East Dr", "London", 123 };

    auto clone = [](Contact c)
    {
        ostringstream oss;
        boost::archive::text_oarchive oa(oss);
        oa << c;

        string s = oss.str();

        Contact result;
        istringstream iss(s);
        boost::archive::text_iarchive ia(iss);
        ia >> result;
        return result;
    };

    Contact jane = clone(john);
    jane.name = "Jane";
    jane.address->street = "123B West Dr";

    cout << john << endl << jane << endl;

    getchar();
    return 0;
}