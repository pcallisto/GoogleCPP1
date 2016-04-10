// implicit-explicit.cpp by Bill Weinman <http://bw.org/>
#include <iostream>

class Rational {
    int _n;
    int _d;
public:                                         //  v--- default init value
    Rational(int numerator = 0, int denominator = 1) : _n(numerator), _d(denominator) {}
    Rational(const Rational & rhs) : _n(rhs._n), _d(rhs._d) {}	// copy constructor
    ~Rational();
    inline int numerator() const { return _n; }
    inline int denominator() const { return _d; }
    Rational & operator = (const Rational &);
    //    Rational operator + ( const Rational & ) const;
    Rational operator - (const Rational &) const;
    Rational operator * (const Rational &) const;
    Rational operator / (const Rational &) const;
    operator std::string() const;
};

Rational & Rational::operator = (const Rational & rhs) {
    if (this != &rhs) {
        std::cout << "assignment" << std::endl;
        _n = rhs.numerator();
        _d = rhs.denominator();
    }
    return *this;
}

Rational Rational::operator - (const Rational & rhs) const {
    return Rational((_n * rhs._d) - (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator * (const Rational & rhs) const {
    return Rational(_n * rhs._n, _d * rhs._d);
}

Rational Rational::operator / (const Rational & rhs) const {
    return Rational(_n * rhs._d, _d * rhs._n);
}

Rational::~Rational() {
    std::cout << "destructor: " << _n << '/' << _d << std::endl;
}

Rational::operator std::string() const {
    const static int maxstring = 64;
    char s[maxstring];
    int ret = snprintf(s, maxstring, "%d/%d", _n, _d);
    return std::string(s);
}
Rational operator + (const Rational & lhs, const Rational & rhs) {
    return Rational((lhs.numerator() * rhs.denominator()) + (lhs.denominator() * rhs.numerator()),
        lhs.denominator() * rhs.numerator());
}

// useful for std::cout
std::ostream & operator << (std::ostream & o, const Rational & r) {
    return o << r.numerator() << '/' << r.denominator();
}

int mainRational() {
    using namespace std;

    Rational a = 7;		// 7/1
    cout << "a is: " << a << endl;
    Rational b(5, 3);	// 5/3
    cout << "b is: " << b << endl;
    Rational c = b;		// copy constructor
    cout << "c is: " << c << endl;
    Rational d;			// default constructor
    cout << "d is: " << d << endl;
    d = c;				// assignment operator
    cout << "d is: " << d << endl;
    Rational & e = d;	// reference
    d = e;				// assignment to self!
    cout << "e is: " << e << endl;

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    cout << 14 << " + " << b << " = " << 14 + b << endl;

    string s = "Rational is a string: ";
    s += b;
    cout << s.c_str() << endl;
    return 1;
}