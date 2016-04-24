#pragma once

//#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <memory>
#include <iostream>

using namespace std;

template <typename T> struct Maybe;

template <typename T> Maybe<T> maybe(T* context)
{
    return Maybe<T>(context);
}

template <typename T> struct Maybe
{
    T* context;

    explicit  Maybe(T* const context)
        : context{ context }
    {
    }
    template <typename Func>
    auto With(Func evaluator)
    {
        if (context == nullptr)
        {           // here we remove the pointer
            return Maybe<typename remove_pointer<decltype(evaluator(context))>::type>(nullptr);
        }
        else     // these 2 returns are of the same type
        {
            return maybe(evaluator(context));
        }
    }

    template <typename Func>
    auto Do(Func action)
    {
        if (context != nullptr)  action(context);
        return *this;
    }
};

class Address
{
public:
    string* house_name = nullptr;
};

class Person
{
public:
    Address* address = nullptr;
};

void print_house_name(Person* p)
{
    //    if (p!=nullptr && p->address != nullptr && p->address->house_name!= nullptr){
    //        cout << *p->address->house_name << endl;

    maybe(p)
        .With([](auto x) { return x->address; })
        .With([](auto x) { return x->house_name; })
        .Do([](auto x) { cout << x << endl; });
}

int main()
{
    Person p;
    p.address = new Address;
    p.address->house_name = new string("name");

    print_house_name(&p);

    delete p.address->house_name;
    delete p.address;

    getchar();
    return 0;
}