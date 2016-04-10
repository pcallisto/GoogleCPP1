// exceptions.cpp by Bill Weinman <http://bw.org/>
#pragma warning( disable : 4996 )

#include <cmath>
#include <cerrno>
#include <cstring>
#include <iostream>
#include <exception>

using namespace std;

static string unk = "unknown";
static string clone_prefix = "clone-";

class E : public exception {
    const char * msg;
    E() {}
public:
    E(const char * s) throw() : msg(s) {}
    const char * what() const throw() { return msg; }
};

class Manimal {
    string _type;
    string _name;
    string _sound;
public:
    Manimal();	// default constructor
    explicit Manimal(const string & type, const string & name, const string & sound);

    Manimal(const Manimal &);	// copy constructor
    Manimal & operator=(const Manimal &);	// copy operator
    ~Manimal();	// destructor
    void print() const;
};

Manimal::Manimal() : _type(unk), _name(unk), _sound(unk) {
    cout << "default constructor" << endl;
}

Manimal::Manimal(const string & type, const string & name, const string & sound)
    : _type(type), _name(name), _sound(sound) {
    if (type.length() == 0 || name.length() == 0 || sound.length() == 0) {
        throw E("Insufficient parameters");
    }
    cout << "constructor with parameters" << endl;
}

Manimal::Manimal(const Manimal & a) {
    cout << "copy constructor" << endl;
    _type = a._type;
    _sound = a._sound;
    _name = clone_prefix + a._name;
}

Manimal::~Manimal() {
    cout << "destructor: " << _name.c_str() << " the " << _type.c_str() << endl;
}

void Manimal::print() const {
    cout << _name.c_str() << " the " << _type.c_str() << " says " << _sound.c_str() << endl;
}

Manimal & Manimal::operator=(const Manimal & o) {
    cout << "assignment operator" << endl;
    if (this != &o) {
        _type = o._type;
        _name = clone_prefix + o._name;
        _sound = o._sound;
    }
    return *this;
}

int mainExceptions() {
    try {
        Manimal x("bear", "bill", "sdf");
        x.print();
    }
    catch (exception & e) {
        cerr << "Manimal x: " << e.what() << endl;
    }

    double not_a_number = std::log(-1.0);
    if (errno == EDOM) {
        std::cout << "log(-1) failed: " << std::strerror(errno) << '\n';
    }
    else
        cout << "not_a_number, isn't used: " << not_a_number << endl;
    return 1;
}