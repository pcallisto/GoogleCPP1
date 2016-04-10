// new-delete.cpp by Bill Weinman <http://bw.org/>
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
//#include <QtCore>

using namespace std;

class A {
    int     _a;
    int     _b;
    int     _c;
    char    _s[132];
public:
    A(int);
    ~A();
    int a() { return _a; }
    int b() { return _b; }
    int c() { return _c; }
    char * s() { return _s; }
};

A::A(int i = 0)
    : _a(i),
    _b(i + 1),
    _c(i + 2) {
    cout << "A constructor called" << endl;
}

A::~A() {
    cout << "A destructor called" << endl;
}

int mainNewDelete() {
    cout << "allocating space for one A object" << endl;
    A * a = new (nothrow) A[5];
    if (a == nullptr) {
        cerr << "new A failed." << endl;
        return 1;
    }

    for (int i = 0; i < 5; ++i) {
        printf("a: %d, %d, %d\n", a[i].a(), a[i].b(), a[i].c());
    }
    for (int i = 0; i < 5; ++i) {
        a[i].a(), a[i].b(), a[i].c();
    }

    vector<string> qv;
    delete[] a;
    cout << "space for A object deleted" << endl;
    for (auto i = qv.begin(); i < qv.end(); ++i) {
        std::cout << "This is puked by a vector: " << &i;
    }
    std::cout << endl;

    A classA = 6;
    vector<string> v;
    for (int i = 0; i < 5; ++i) {
        char buff[1032];
        sprintf(buff, "[%d/%d/%d] ", classA.a(), classA.b(), classA.c());
        v.push_back(buff);
    }
    for (auto i = v.begin(); i < v.end(); ++i)
        cout << i->c_str();
    cout << endl;
    return 1;
}