#include "stdafx.h"

template <int n>
int sum(array<int, n> values)
{
    int result = 0;
    for (int value : values)
        result += value;
    return result;
}

int containers()
{
    array<int, 5> numbers = { { 1, 2, 3, 4, 5 } };
    array<int, 3> more_numbers = { { 1, 3, 5 } };
    cout << sum(numbers) << endl;
    cout << sum(more_numbers) << endl;

    vector<float> values{ 1, 2, 3 };
    values.push_back(4.5f);
    values.push_back(5);
    values.pop_back();

    //float v = values[5];

    try {
        float u = values.at(5);
    }
    catch (const std::out_of_range& e)
    {
        cout << e.what() << endl;
    }

    cout << "There are " << values.size() << " values"
        << endl;
    for (float value : values)
        cout << value << "\t";
    cout << endl;

    string speech("to be, or not to be, that is the question");
    set<char> letters;
    for (char c : speech)
    {
        if (isalpha(c)) letters.insert(c);
    }

    for (char c : letters)
        cout << c << "\t";
    cout << endl;

    map<char, int> histogram;

    for (char c : speech)
    {
        if (isalpha(c)) histogram[c]++;
    }

    for (auto u : histogram)
        cout << u.first << " - " << u.second << endl;

    return 0;
}