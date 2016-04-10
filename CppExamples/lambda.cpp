// lambda.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
#include <algorithm>
#include <locale>
#include <vector>
using namespace std;

class fupper {
    char lastc;
public:
    fupper() : lastc(0) {}
    char operator() (char c);
};

char fupper::operator() (char c) {
    if (lastc == ' ' || lastc == 0) {
        lastc = c; return toupper(c);
    }
    else {
        lastc = c; return tolower(c);
    }
}

int mainLambda() {
    string s = "big light in sky slated to appear in east";

    transform(s.begin(), s.end(), s.begin(), fupper());

    cout << s << endl;

    vector<int> v = { 50, -10, 20, -30 };
    std::sort(v.begin(), v.end());  // the default sort now v should be { -30, -10, 20, 50 }

    // sort by absolute value:
    std::sort(v.begin(), v.end(), [](int a, int b) { return abs(a) < abs(b); });
    cout << "\nSorted by abs: ";
    for (auto x : v)
        cout << x << ", ";
    // now v should be { -10, 20, -30, 50 }
    cout << endl;
    return 0;
}