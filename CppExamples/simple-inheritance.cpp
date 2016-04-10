// simple-inheritance.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
//#include <QtCore>
//#include <QString>

using namespace std;

// Base class
class Animal {
    string _name;
    string _type;
    string _sound;
    int    _count;
    // private constructor prevents construction of base class
    Animal() {}
    //protected:
        // protected constructor for use by derived classes
    Animal(const string & n, const string & t, const string & s)
        : _name(n), _type(t), _sound(s) {}
    friend class Dog;
    friend class Cat;
    friend class Pig;
public:
    virtual void speak() const;
    const string & name()  const { return _name; }
    const string & type()  const { return _type; }
    const string & sound() const { return _sound; }
    virtual ~Animal() {}
};

void Animal::speak() const {
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

class Fur {
    string _type;
protected:
    Fur(const string & f) : _type(f) {}
public:
    const string & type() const { return _type; }
};

// Dog class - derived from Animal
class Dog : public Animal {
    int walked;
public:
    Dog(string n) : Animal(n, "dog", "woof"), walked(0) {}
    int walk() { return ++walked; }
};

// Cat class - derived from Animal
class Cat : public Animal, public Fur {
    int petted;
public:
    Cat(string n) : Animal(n, "cat", "meow"), Fur(string("silky")), petted(0) {}
    int pet() { return ++petted; }
    void grooming();
    void speak() const;
};
void Cat::speak() const {
    cout << "purrrr" << endl;
}
void Cat::grooming() {
    cout << Animal::name().c_str() << " grooms his " << Fur::type().c_str() << " fur" << endl;
}
// Pig class - derived from Animal
class Pig : public Animal {
    int fed;
public:
    Pig(string n) : Animal(n, "pig", "oink"), fed(0) {}
    int feed() { return ++fed; }
    string speakLatin() const;
};

string Pig::speakLatin() const {
    return string(Animal::name() + "-ay");
}

class Zoo {
    int numberOfAnimals;

    Dog dog;
    Cat cat;
    Pig pig;
};

int mainSimpleInheritance() {
    cout << "\n\n simpleInheritance() -----------------------------------------------------\n";
    Dog d("Fibonacci");
    Cat c("Purcy");
    Pig p("Petie");

    Animal *ap[] = { &d, &c, &p, nullptr };
    for (int i = 0; ap[i]; ++i)
        ap[i]->speak();

    //    d.speak();
    //	  c.speak();
    //    p.speak();

    //    for (int a=1;a< a+1; ++a)

    for (int i = 0; i < 232; ++i)
        d.walk();

    cout << d.name().c_str() << " the dogggg has been walked " << d.walk() << " times" << endl;
    cout << c.name().c_str() << " the cat has been petted " << c.pet() << " times" << endl;
    cout << p.name().c_str() << " the pig has been fed " << p.feed() << " times" << endl;
    cout << p.speakLatin().c_str() << endl;
    c.grooming();
    return 1;
}