// set.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
#include <set>

using namespace std;

int mainSet() {
    cout << "set of strings from initializer list (C++11): " << endl;
    set<string> strset = { "one", "two", "three", "four", "five" };
    cout << "size: " << strset.size() << endl;
    for (string s : strset) {
        cout << s.c_str() << " ";
    }
    cout << endl << endl;

    cout << "insert element \"six\"" << endl;
    strset.insert("six");
    for (string s : strset) {
        cout << s.c_str() << " ";
    }
    cout << endl << endl;

    cout << "insert duplicate element \"five\"" << endl;
    pair<set< string>::iterator, bool > rvinsert;
    bool & insertSuccess = rvinsert.second;             // reference to second element
    rvinsert = strset.insert("five");
    if (insertSuccess) {
        for (string s : strset) {
            cout << s.c_str() << " ";
        }
    }
    else cout << "insert failed";
    cout << endl << endl;

    // multiset allows duplicates
    multiset<string> strMultiSet = { "one", "two", "three", "four", "five" };
    cout << "insert element \"five\"" << endl;
    strMultiSet.insert("five");
    strMultiSet.insert("five");
    strMultiSet.insert("five");
    strMultiSet.insert("five");

    for (string s : strMultiSet)
        cout << s.c_str() << " ";
    cout << endl;

    strset.erase(strset.find("two"));  // <- dangerous, if 'two; fails... crash
    for (string s : strset)
        cout << s.c_str() << " ";
    cout << endl;

    cout << "find and erase element \"six\"" << endl;
    set<string>::iterator it = strset.find("six");
    if (it != strset.end()) {
        cout << "found " << it->c_str() << endl;
        strset.erase(it);
    }
    else {
        cout << "not found" << endl;
    }
    for (string s : strset) {
        cout << s.c_str() << " ";
    }
    cout << endl << endl;

    return 0;
}