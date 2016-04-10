#include <iostream>

using namespace std;

// Base class
class Beast {
    string _name;
    string _type;
    string _sound;
    int    _count;
    // private constructor prevents construction of base class
    Beast() {}
    //protected:
        // protected constructor for use by derived classes
    Beast(const string & n, const string & t, const string & s)
        : _name(n), _type(t), _sound(s) {}
    friend class Lion;
    friend class Elephant;
    friend class Gorilla;
public:
    virtual void speak() const;
    virtual void reset(const string & n, const string & t, const string & s);
    const string & getName()  const { return _name; }
    const string & getType()  const { return _type; }
    const string & getSound() const { return _sound; }
    void setName(const string  &n) {
        _name = n;
    }
    void setType(const string  &t) { _type = t; }
    void setSound(const string  &s) { _sound = s; }
    virtual ~Beast() {}
};

void Beast::speak() const {
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

void Beast::reset(const string & name, const string & type, const string & sound)
{
    setName(name);
    setType(type);
    setSound(sound);
    //	cout << "Reset will change the " << this->getName  << " for a " << type << " named " << name << "." << endl;
}

class Fur {
    string _type;
protected:
    Fur(const string & f) : _type(f) {}
public:
    const string & getType() const { return _type; }
};

// Lion class - derived from Beast
class Lion : public Beast {
    int walked;
public:
    Lion(string n) : Beast(n, "lion", "wooflike-roar-man"), walked(0) {}
    int walk() { return ++walked; }
};

// Elephant class - derived from Beast
class Elephant : public Beast, public Fur {
    int petted;
public:
    Elephant(string n) : Beast(n, "elephant", "pnhreeeh"), Fur(string("ragged")), petted(0) {}
    int pet() { return ++petted; }
    void grooming();
    void speak() const;
};
void Elephant::speak() const {
    cout << "moooooove-outa-my-way-dude" << endl;
    Beast::speak();
}
void Elephant::grooming() {
    cout << Beast::getName().c_str() << " grooms his " << Fur::getType().c_str() << " fur" << endl;
}
// Gorilla class - derived from Beast
class Gorilla : public Beast {
    int fed;
public:
    Gorilla(string n) : Beast(n, "gorilla", "what-up-g"), fed(0) {}
    int feed() { return ++fed; }
    string speakLatin() const;
    void speak() const;
};

string Gorilla::speakLatin() const {
    return string(Beast::getName() + "-ay");
}
void Gorilla::speak() const {
    Beast::speak();
    cout << "<<-- Me is no dum-dum, me say what he say" << endl;
}

class Zoo {
    int numberOfBeasts;

    Lion        lion;
    Elephant    elephant;
    Gorilla     gorilla;
};

int mainComplexInheritance() {
    cout << "\n\n complexInheritance() -----------------------------------------------------\n" << "thats" << endl;
    Lion     l("Leon");
    Elephant e("Ellie-May");
    Gorilla  g("Father Oblivian");
    cout << "Classes created." << endl;
    Beast *ap[] = { &l, &e, &g, nullptr };// array of pointers
    for (int i = 0; ap[i]; ++i) {
        ap[i]->speak();
        cout << "for loop run" << endl;
    }
    cout << "for loop speak()." << endl;

    l.speak();
    e.speak();
    g.speak();
    cout << "Direct call speak." << endl;
    l.reset("Wally", "chimp", "arf-me-out");
    l.speak();
    l.reset("Leo-nardo", "big kitty-cat", "arf-me-out");
    e.reset("Eugene", "non-elephant", "nuts nuts nuts, i'm nuts for nuts");
    g.reset("Gloria", "girlilla", "me likey banana");
    cout << "Post reset speak." << endl;
    l.speak();
    e.speak();
    g.speak();

    for (int i = 0; i < 232; ++i)
        l.walk();

    cout << l.getName().c_str() << " the Lion has been walked " << l.walk() << " times" << endl;
    cout << e.getName().c_str() << " the Elephant has been petted " << e.pet() << " times" << endl;
    cout << g.getName().c_str() << " the Gorilla has been fed " << g.feed() << " times" << endl;
    cout << g.speakLatin().c_str() << endl;
    e.grooming();
    return 1;
}