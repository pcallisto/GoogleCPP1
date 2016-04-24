#include "stdafx.h"

int streams()
{
    cout << "text " << 42 << " " << false << endl;
    cout << boolalpha;
    cout << true << " " << false << endl;

    int width;
    float height;
    cout << "Enter width: ";
    cin >> width;
    cout << "Enter height: ";
    cin >> height;
    auto area = width * height;
    cout << "Area = " << area << endl;

    ostringstream oss;
    oss << "Width is " << width << ", ";
    oss << "Height is " << height << ", ";
    oss << "Area is " << area;

    string text = oss.str();
    cout << text << endl;

    ofstream ofs("info.txt");
    string s;

    while ((cin >> s) && (s != "q"))
    {
        ofs << s << endl;
    }

    return 0;
}