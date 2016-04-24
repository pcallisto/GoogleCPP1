#include "stdafx.h"

const double M_PI = 3.1459;

int accelCppNumerics()
{
    cout << "Maximum integer is " <<
        numeric_limits<int>::max() << endl;

    cout << sin(M_PI / 2) << endl;

    vector<int> v{ 1, 2, 3, 4 };
    next_permutation(v.begin(), v.end());
    for (auto i : v) cout << i << "\t";
    cout << endl;

    complex<float> f(0.4f, 0.5f);
    cout << f*f << endl;

    srand((unsigned)time(nullptr));
    for (int i = 0; i < 100; ++i)
    {
        cout << rand() % 10 << "\t";
    }

    auto seed = chrono::system_clock::now()
        .time_since_epoch().count();
    mt19937 gen(seed);
    normal_distribution<float> nd;

    for (size_t i = 0; i < 100; i++)
    {
        cout << nd(gen) << "\t";
    }

    return 0;
}