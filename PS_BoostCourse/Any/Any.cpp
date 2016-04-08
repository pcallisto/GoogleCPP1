#include "stdafx.h"

int main(int argc, char* argv[])
{
    any w;
    any x{ 2.0 };
    vector<any> y{ 42,                         // int
                    "life",                     // char *
                    string(" is good."),        // std::string
                    vector<int>{123,-9,321,666,626,747,707} };  // std::vector<int>

    any z = string("test");

    if (!x.empty())
        cout << x.type().name() << endl;

    int a = any_cast<int>(y[0]);
    cout << "The value is " << a << endl;

    try
    {
        int b = any_cast<int>(y[1]);
    }
    catch (const bad_any_cast& e)
    {
        cout << "wrong type" << &e << endl;
    }

    for (any a : y)
    {
        int* value = any_cast<int>(&a);
        if (value != nullptr)
            cout << "boost::any_cast<> [0] is an int: " << *value << endl;

        const char** text = any_cast<const char*>(&a);
        if (text != nullptr)
            cout << "boost::any_cast<> [1] is a char *: " << *text << endl;

        string* str = any_cast<string>(&a);
        if (str != nullptr)
        {
            cout << "boost::any_cast<> [2] is a std::string: ";
            str->insert(0, " really"); // std::string.insert()
            cout << *str << endl;
        }

        vector<int>* boostv = any_cast<vector<int>>(&a);
        if (boostv != nullptr)
        {
            cout << "boost::any_cast<> [3] is a std::vector<int>: ";
            for (int boostv_i : *boostv)
            {
                cout << boostv_i << " ";
            }
            cout << endl;
        }
    }

    getchar();
    return 0;
}