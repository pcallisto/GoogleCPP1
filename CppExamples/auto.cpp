// auto.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
#include <typeinfo>
using namespace std;

template<typename lhsT, typename rhsT>
auto tf(lhsT lhs, rhsT rhs) -> decltype(lhs + rhs) { // here the template let's the compile figure out the types
    return lhs + rhs;								 // involved in the addition and returns the right type
}

int mainAuto() {
    int i = 47;
    const char * cstr = "this is a c-string";
    string sclass = string("this is a string class string");
    auto x = string("this is a string class string");
    decltype(x) y;

    cout << "type of i is " << typeid(i).name() << endl;
    cout << "type of cstr is " << typeid(cstr).name() << endl;
    cout << "type of sclass is " << typeid(sclass).name() << endl;
    cout << "type of x is " << typeid(x).name() << endl;
    cout << "type of y is " << typeid(y).name() << endl;

    for (string::const_iterator s_it = sclass.begin(); s_it != sclass.end(); ++s_it) {
        cout << *s_it << " ";
    }
    cout << endl;

    for (auto it = sclass.begin(); it != sclass.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    for (auto c : sclass) cout << c << " ";
    cout << endl;

    auto z = tf(sclass, cstr);
    cout << "type if z is " << typeid(z).name() << endl;

    return 0;
}