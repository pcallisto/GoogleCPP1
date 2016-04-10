// template-function.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
using namespace std;

template <typename Type> Type maxof(Type a, Type b) {
    return (a > b ? a : b);
}

int mainTemplateFunction() {
    cout << maxof(7, 9) << endl;
    return 0;
}