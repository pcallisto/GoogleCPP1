// function-object.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
using namespace std;

class MultBy {
    int mult;
public:
    MultBy(int n) : mult(n) {} //initializer sets  mult to n
    ~MultBy();
    int getMult() { return mult; }
    void doMult(int m) {
        cout << "applying factor to mult" << endl;
        mult *= m;
    }
    int operator () (int n) { return mult * n; } // function operator
};
MultBy::~MultBy() {
    std::cout << "Destruction: " << mult << std::endl;
}
int mainFunctionObject() {
    MultBy times4(4);
    MultBy times10(10);
    MultBy times15(15);
    cout << "times4(5) is " << times4(5) << endl;
    times4.doMult(8);
    cout << "times4(15) is " << times4(15) << endl;
    cout << "times10(5) is " << times10(5) << endl;
    cout << "times10(15) is " << times10(15) << endl;
    cout << "times15(5) is " << times15(5) << endl;
    cout << "times15(15) is " << times15(15) << endl;
    char buff[64];
    sprintf_s(buff, "varname's mult is: %d", times4.getMult());
    cout << buff << endl;
    return 1;
}