#include <iostream>
#include <vector>
#include <cstdio>
#include <limits>
#include <list>
#include <cstdint>
#include <cinttypes>

using namespace std;

template <typename T, typename U> U maxof(T a, U b) {
    printf("%d ", a);
    double aa = (float)a;
    printf("%08.04f\n", b);
    return (aa > b ? aa : b);
}
template <typename T> T maxofs(T a, T b) {
    //    printf("a:%s, b:%s\n", a, b);
    return (a > b ? a : b);
}

template<typename cT, typename retT = cT, typename sepT = decltype(cT::value_type)> retT joinContainer(const cT & o, const sepT & sep)
{
    retT out;
    auto it = o.begin();
    while (it != o.end())
    {
        out += *it;
        if (++it != o.end()) out += sep;
    }
    return out;
}
//-----------------------------------------------------------------------------
int mainJoin() {
    cout << "maxof: " << maxof(4, 5.4) << endl;
    cout << "maxofs: " << maxofs("aaaaaaa", "bbbbbbb") << endl;
    cout << "maxofs: " << maxofs<string>("aaaaaaa", "bbbbbbb").c_str() << endl;

    string s1("This is a string");
    string s2("This is also a string");
    string s3("Yet another string");

    // join the characters of a string
    cout << joinContainer(s1, ':').c_str() << endl;

    // join strings from a vector, returning a string
    list<string> vs({ s1, s2, s3 });
    cout << joinContainer<list<string>, string>(vs, ", ").c_str();
    return 1;
}