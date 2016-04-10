// tuple.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
#include <utility>
#include <tuple>

using namespace std;

int mainTuple() {
    cout << "++ mainTuple()--------------------------------------------------------------\n";
    pair<int, string> p(42, "forty-two");
    cout << p.first << " " << p.second.c_str() << endl;

    p = make_pair<int, string>(112, "one-one-two");
    cout << p.first << " " << p.second.c_str() << endl;

    tuple<string, int, string> t1("one", 5, "three");
    cout << get<0>(t1).c_str() << " " << get<1>(t1) << " " << get<2>(t1).c_str() << endl;

    string a, c;
    int b;
    tie(a, b, c) = t1;
    cout << a.c_str() << " " << b << " " << c.c_str() << endl;

    tuple<string, string, string> t2;
    tie(get<2>(t2), get<1>(t2), get<0>(t2)) = t1;
    cout << get<0>(t2).c_str() << " " << get<1>(t2).c_str() << " " << get<2>(t2).c_str() << endl;
    auto t3 = t2;
    cout << get<0>(t2).c_str() << " " << get<1>(t2).c_str() << " " << get<2>(t2).c_str() << endl;
    cout << get<0>(t3).c_str() << " " << get<1>(t3).c_str() << " " << get<2>(t3).c_str() << endl;

    return 0;
}