#include "stdafx.h"


class MyTokenizer
{
public:
    template <typename II, typename Token>
    bool operator()(II& next, II end, Token& tok)
    {
        return true;
    }

    void reset()
    {
    }
};

void token_demo()
{
    char_separator<char> sep("o", " ", keep_empty_tokens);
    string s = "To be, or not to be?";
    tokenizer<char_separator<char>> t(s, sep);

    for (string part : t)
        cout << "<" << part << ">" << endl;

    int offsets[] = { 2, 3, 4 };
    offset_separator os(offsets, offsets + 3);

    auto start = make_token_iterator<string>(s.begin(), s.end(), os);
    auto end = make_token_iterator<string>(s.end(), s.end(), os);

    for (; start != end; ++start)
        cout << *start << endl;

    tokenizer<MyTokenizer> tt(s, MyTokenizer());
}

void lc_demo()
{
    string s = "2.1";

    double d = lexical_cast<double>(s);

    string ss = "12345";
    int n = lexical_cast<int>(ss);

    cout << d << ", " << n << endl;

    try {
        lexical_cast<int>("abcde");
    }
    catch (const bad_lexical_cast& e)
    {
        cout << e.what() << endl;
    }
}

void algo_demo()
{
    string test = "hello  world\r\n";
    trim(test);
    cout << "<" << test << ">" << endl;
    trim_all(test);
    cout << "<" << test << ">" << endl;
    to_upper(test);
    cout << "<" << test << ">" << endl;
}

enum class Color
{
    Red,
    Green,
    Blue
};

typedef bimap<Color, string> ColorMapType;

ColorMapType colorTypes;

void bimap_demo()
{
    colorTypes.insert(ColorMapType::value_type(Color::Red, "red"));

    Color c = colorTypes.right.at("red");

    string s = colorTypes.left.at(Color::Red);
}

void units_demo()
{
    typedef make_scaled_unit<si::length, scale<10, static_rational<-2>>>::type cm;

    quantity<cm> d(2.0 * si::meters);
    quantity<si::time> t(100.0 * si::seconds);

    quantity<si::velocity> x(d / t);
}

int main(int argc, char* argv[])
{
    lc_demo();

    units_demo();

    getchar();
    return 0;
}