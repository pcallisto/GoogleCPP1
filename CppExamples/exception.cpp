// exception.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
#include <exception>
using namespace std;

class myexception : public exception {
    string s;
public:
    myexception(const char * message) : s(message) {}
    const char * what() const throw();
};

const char * myexception::what() const throw() {
    return s.c_str();
}

const myexception e_ouch("ouch!");
const myexception e_bad("this is bad!");
const myexception e_worse("dont' do that!");

void TraceErr() {
    cout << "this is a broken function" << endl;
    throw e_worse;
}

int mainException() {
    try {
        cout << "let's have an emergency!" << endl;
        TraceErr();
    }
    catch (exception & e) {
        cout << e.what() << endl;
    }

    cout << "Not the end of the world, we're still running." << endl;
    return 0;
}