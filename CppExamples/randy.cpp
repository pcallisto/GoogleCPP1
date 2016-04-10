#include <iostream>
#include <random>
#include <set>

using namespace std;

int mainRandy()
{
    const unsigned int maxCount = 9873;
    const unsigned int stepCount = (maxCount / 100);
    vector<int> intVector{};
    set<int> intSet{};
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 610);

    for (int i = 0; i != 610; ++i) {
        cout << dist(mt) << " ";
    }
    cout << endl;

    for (int i = maxCount; i != 0; --i) {
        intVector.push_back(i);
        intSet.insert(intVector.back());
        if (i % stepCount)
            continue;
        else
            cout << intVector.back() << " ";
    }
    cout << endl;

    //    for (set<int>::iterator it = intSet.begin(); it != intSet.end() ; ++it) {
    for (auto it : intSet) {
        if (it % stepCount)
            continue;
        cout << it << " ";
    }
    cout << endl;

    for (auto i : intVector)
    {
        set<int>::iterator findIt = intSet.find(i);
        if (i % stepCount)
            continue;
        if (findIt != intSet.end()) {
            cout << "found:" << i;
        }
        else {
            cout << "couldn't find: " << i;
        }
        cout << endl;
    }

    return 1;
}