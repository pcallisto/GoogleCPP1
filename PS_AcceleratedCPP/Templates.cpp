#include "stdafx.h"

typedef pair<int, int> int_pair;
//typedef tuple<int, int, int> trie;

int_pair sum_and_product(int a, int b)
{
    return int_pair(a + b, a*b);
}

//trie sum_product_avg(int a, int b, int c)
//{
//  trie t{ a + b + c, a*b*c, (a + b + c) / 3 };
//  return t;
//}

template<typename T1, typename T2, typename T3>
struct triple
{
    typedef T1 result_type;

    T1 first;
    T2 second;
    T3 third;

    triple(const T1& first, const T2& second, const T3& third)
        : first(first), second(second), third(third) {}
};

typedef triple<int, int, int> trie;

//trie sum_product_avg(int a, int b, int c)
//{
//  return trie(a + b + c, a*b*c, (a + b + c) / 3);
//}

template<typename T1, typename T2, typename T3>
triple<T1, T2, T3> sum_product_avg(
    const T1& a, const T2& b, const T3& c
)
{
    return triple<T1, T2, T3>(a + b + c, a*b*c, (a + b + c) /
        triple<T1, T2, T3>::result_type(3));
}

void consuming_templates()
{
    int a = 2, b = 3;
    auto result = sum_and_product(a, b);
    //cout << "sum = " << result.first <<
    //  " product = " << result.second << endl;
    cout << "sum = " << get<0>(result) <<
        " product = " << get<1>(result) << endl;

    double c = 4.5;
    /*auto result2 = sum_product_avg(a, b, c);
    cout << "sum = " << get<0>(result2) <<
      " product = " << get<1>(result2) <<
      " average = " << get<2>(result2) << endl;*/

    auto result2 = sum_product_avg(a, b, c);
    cout << "sum = " << result2.first <<
        " product = " << result2.second <<
        " average = " << result2.third << endl;
}

void template_functions()
{
    int a = 14;
    double b = 5.0;
    float c = -3.5f;

    auto result = sum_product_avg(a, b, c);
    cout << "sum = " << result.first <<
        " product = " << result.second <<
        " average = " << result.third << endl;
}

typedef complex<double> cd;
typedef triple<cd, cd, cd> cdt;

template<> cdt sum_product_avg(const cd& a,
    const cd& b, const cd& c)
{
    auto result = sum_product_avg(a.real(), b.real(), c.real());
    return cdt(result.first, result.second, result.third);
}

void template_specialization()
{
    cd a(2, 3), b(3, 4), c(4, 5);
    auto result = sum_product_avg(a, b, c);
    cout << result.first << ", " << result.second
        << ", " << result.third << endl;
}

template <typename T>
T sum(T t) { return t; }

template<typename T, typename ...U>
auto sum(T t, U ...u) -> decltype(t + sum(u...))
{
    return t + sum(u...);
}

void variadic()
{
    //    cout << sum(1, 2, 3, 4) << endl;
    //    cout << sum(1, 2.5, 3, 4) << endl;
    cout << sum(string("abra"), string("cadabra")) << endl;
}

template <int n> struct Factorial
{
    enum { value = n * Factorial<n - 1>::value };
};

template <> struct Factorial<0>
{
    enum { value = 1 };
};

void metaprogramming()
{
    int x = Factorial<4>::value;
    int y = Factorial<0>::value;
}

int Templates()
{
    //consuming_templates();
    //template_functions();
    //template_specialization();
    //variadic();
    metaprogramming();

    getchar();
    return 0;
}