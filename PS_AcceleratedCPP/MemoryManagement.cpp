#include "stdafx.h"

class Address
{
public:
    string city;

    Address() {}

    Address(string const& city) : city(city)
    {
        cout << city << " created" << endl;
    }
    ~Address()
    {
        cout << city << " destroyed" << endl;
    }
};

class Person
{
public:
    Address *address;

    Person(string const& city)
    {
        address = new Address(city);
        cout << "Person created" << endl;
    }

    ~Person()
    {
        delete address;
        cout << "Person destroyed" << endl;
    }
};

class Person2
{
    Person2() {}
    Person2(const Person2& _) {}
    ~Person2() {}

    int ref_count;
public:
    static Person2* create()
    {
        auto* p = new Person2;
        p->ref_count = 1;
        return p;
    }
    void add_ref() { ref_count++; }
    void release()
    {
        if (--ref_count == 0)
            delete this;
    }
};

class Person3
{
public:
    shared_ptr<Address> address;

    Person3(string const& city)
    {
        address = make_shared<Address>(city);
        cout << "Created person" << endl;
    }

    ~Person3()
    {
        cout << "Destroyed person" << endl;
    }
};
int inc(int& a) { return a++;}

int meaningOfLife() { return 42; }

void move_rvalue()
{
    int a = 0;
    inc(a);

    //inc(1);
    //int& x = meaningOfLife();
    int&& y = meaningOfLife();
    cout << y << endl;

    Address book[100];
    book[55] = move(Address("Paris"));

    auto swap = [](int& a, int& b)
    {
        int tmp{ a };
        a = b;
        b = tmp;
    };

    auto betterSwap = [](int& a, int& b)
    {
        int tmp(move(a));
        a = move(b);
        b = move(tmp);
    };

    int x = 2, z = 5;
    swap(x, z);
}

unique_ptr<Address> create_address(string const& city)
{
    //auto* a = new Address(city);
    //a->city = "New " + city;
    //return unique_ptr<Address>(a);
    return make_unique<Address>(city);
}

int MemoryManagment(int argc, char* argv)
{
    shared_ptr<Address> a;

    {
        Person3 p("Paris");
        a = p.address;
    }

    cout << a->city << endl;

    return 0;
}