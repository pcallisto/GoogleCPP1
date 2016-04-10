// simple-inheritance.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
//#include <QtCore>
//#include <QString>

using namespace std;

// Base class
class Banimal {
    string _name;
    string _type;
    string _sound;
    int    _count;
    // private constructor prevents construction of base class
    Banimal() {}
    //protected:
        // protected constructor for use by derived classes
    Banimal(const string & n, const string & t, const string & s)
        : _name(n), _type(t), _sound(s) {}
    friend class Flog;
    friend class Bat;
    friend class Sprig;
    friend const string & getBaninalName(const Banimal &);

public:
    virtual void speak() const;
    const string & name()  const { return _name; }
    const string & type()  const { return _type; }
    const string & sound() const { return _sound; }
    virtual ~Banimal() {}
};

void Banimal::speak() const {
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

class Fur {
    string _type;
protected:
    Fur(const string & f) : _type(f) {}
public:
    const string & type() const { return _type; }
};

// Flog class - derived from Banimal
class Flog : public Banimal {
    int walked;
public:
    Flog(string n) : Banimal(n, "dog", "woof"), walked(0) {}
    int walk() { return ++walked; }
};

// Bat class - derived from Banimal
class Bat : public Banimal, public Fur {
    int petted;
public:
    Bat(string n) : Banimal(n, "Bat", "meow"), Fur(string("silky")), petted(0) {}
    int pet() { return ++petted; }
    void grooming();
    void speak() const;
};
void Bat::speak() const {
    cout << "purrrr" << endl;
}
void Bat::grooming() {
    cout << Banimal::name().c_str() << " grooms his " << Fur::type().c_str() << " fur" << endl;
}
// Sprig class - derived from Banimal
class Sprig : public Banimal {
    int fed;
public:
    Sprig(string n) : Banimal(n, "pig", "oink"), fed(0) {}
    int feed() { return ++fed; }
    string speakLatin() const;
};

string Sprig::speakLatin() const {
    return string(Banimal::name() + "-ay");
}

const string & getBaninalName(const Banimal & a) {
    return a._name;
}

class Zoo {
    int numberOfBanimals;

    Flog dog;
    Bat cat;
    Sprig pig;
};

int mainFriendInheritance() {
    cout << "\n\n friendInheritance() -----------------------------------------------------\n";
    Flog d("Fibonacci");
    Bat c("Purcy");
    Sprig p("Petie");

    Banimal *ap[] = { &d, &c, &p, nullptr };
    for (int i = 0; ap[i]; ++i)
        ap[i]->speak();

    for (int i = 0; i < 232; ++i)
        d.walk();

    cout << d.name().c_str() << " the dog has been walked " << d.walk() << " times" << endl;
    cout << c.name().c_str() << " the cat has been petted " << c.pet() << " times" << endl;
    cout << p.name().c_str() << " the pig has been fed " << p.feed() << " times" << endl;
    cout << p.speakLatin().c_str() << endl;
    c.grooming();
    cout << "The dog is named: " << getBaninalName(c).c_str() << '\n';
    return 1;
}