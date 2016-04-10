// map.cpp by Bill Weinman <http://bw.org/>
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <map>
#include <string>

using namespace std;

int mainMap() {
    cout << "map of strings from initializer list (C++11): " << endl;
    map<string, string> strmap = { { "George", "Father" }, { "Ellen", "Mother" },
            { "Ruth", "Daughter" }, { "Spike", "Neighbor's Son" } };
    map<string, string>::iterator it;	// will use throughout

    char buf[64];
    size_t sz = 0;
    string s = strmap["George"];
    int len = sprintf(buf, "%s", s.c_str());

    cout << "size is " << strmap.size() << endl;
    cout << "check a couple of key/value pairs" << endl;
    cout << "George is " << buf << endl;

    s = strmap.find("Ellen")->second;
    len = sprintf(buf, "%s", s.c_str());
    cout << "Ellen is " << buf << endl;
    cout << endl;

    cout << "iterate the set" << endl;
    for (it = strmap.begin(); it != strmap.end(); it++) {
        cout << it->first << " is " << it->second << endl;
    }
    cout << endl;

    cout << "insert an element" << endl;
    // strmap.insert( pair<string, string>("Luke", "Neighbor") );	// pre-C++11
    strmap.insert({ "Luke", "Neighbor" });	// initializer list (C++11)
    cout << "inserted - size is " << strmap.size() << endl;
    for (it = strmap.begin(); it != strmap.end(); it++) {
        cout << it->first << " is " << it->second << endl;
    }
    cout << endl;

    cout << "insert a duplicate" << endl;
    strmap.insert({ "Luke", "Neighbor" });
    cout << "after insert size is " << strmap.size() << endl;
    for (it = strmap.begin(); it != strmap.end(); it++) {
        cout << it->first << " is " << it->second << endl;
    }
    cout << endl;

    cout << "find and erase an element" << endl;
    it = strmap.find("Luke");
    if (it != strmap.end()) {
        cout << "found " << it->first << ":" << it->second << endl;
        strmap.erase(it);
        cout << "erased - size is " << strmap.size() << endl;
    }
    else {
        cout << "not found" << endl;
    }
    for (it = strmap.begin(); it != strmap.end(); it++) {
        cout << it->first << " is " << it->second << endl;
    }
    cout << endl;

    multimap<string, string> strMultimap = { { "George", "Father" }, { "Ellen", "Mother" },
            { "Ruth", "Daughter" }, { "Spike", "Neighbor's Son" } };
    multimap<string, string>::iterator itMulti;	// will use throughout

    cout << "insert a duplicate" << endl;
    strMultimap.insert({ "Luke", "Neighbor" });
    strMultimap.insert({ "Luke", "Neighbor" });
    strMultimap.insert({ "Luke", "Neighbor" });
    cout << "after insert size is " << strMultimap.size() << endl;
    for (itMulti = strMultimap.begin(); itMulti != strMultimap.end(); itMulti++) {
        cout << itMulti->first << " is " << itMulti->second << endl;
    }
    cout << endl;

    for (auto iMulti : strMultimap)
        cout << "First is " << iMulti.first << " and second is " << iMulti.second << endl;
    cout << endl;

    cout << "find and erase an element" << endl;

    for (itMulti = strMultimap.find("Luke"); itMulti != strMultimap.end(); itMulti = strMultimap.find("Luke")) {
        cout << "found " << itMulti->first << ":" << itMulti->second << endl;
        strMultimap.erase(itMulti);
        cout << "erased - size is " << strMultimap.size() << endl;
    }
    cout << "fancy for loop, for remove" << endl;

    strMultimap.insert({ "Luke", "Neighbor" });
    strMultimap.insert({ "Luke", "Neighbor" });
    strMultimap.insert({ "Luke", "Neighbor" });

    while ((itMulti = strMultimap.find("Luke")) != strMultimap.end()) {
        cout << "found " << itMulti->first << ":" << itMulti->second << endl;
        strMultimap.erase(itMulti);
        cout << "erased - size is " << strMultimap.size() << endl;
    }
    cout << "simple while loop, for remove" << endl;

    strMultimap.insert({ "Luke", "Neighbor" });
    strMultimap.insert({ "Luke", "Neighbor" });
    strMultimap.insert({ "Luke", "Neighbor" });

    do {
        itMulti = strMultimap.find("Luke");
        if (itMulti != strMultimap.end()) {
            cout << "found " << itMulti->first << ":" << itMulti->second << endl;
            strMultimap.erase(itMulti);
            cout << "erased - size is " << strMultimap.size() << endl;
        }
        else
            break;
    } while (1);
    cout << "tormented do.. while loop, for remove" << endl;

    for (it = strMultimap.begin(); it != strMultimap.end(); it++) {
        cout << it->first << " is " << it->second << endl;
    }
    cout << endl;

    return 0;
}