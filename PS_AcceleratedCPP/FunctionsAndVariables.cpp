#include "stdafx.h"

namespace life
{
    auto meaning = 42;
    auto* pm = &meaning;
    auto& rm = meaning;
}

void functions_and_vars()
{
    std::cout << "Hello, World!" << std::endl;

    using namespace life;
    std::cout << meaning << " takes up " <<
        sizeof(meaning) << " bytes" << std::endl;
    *pm = 43;
    std::cout << meaning << std::endl;
    rm = 42;
    std::cout << meaning << std::endl;
}

void stack_and_heap()
{
    std::string s("hello");
    std::string* t = new std::string("world");

    delete t;

    int* values = new int[128];

    delete[] values;
}

void functions(char* argv[])
{
    using namespace std;
    cout << argv[0] << endl;

    int n = 10;
    cout << n << endl;
    inc(n);
    cout << n << endl;
}

void lambdas()
{
    using namespace std;
    int x = 4;

    auto doubleValue = [](int z) { return z * 2; };

    cout << x << "*2 = " << doubleValue(x) << endl;

    int y = 5;

    auto increaseByY = [&y](int z) { return y + z; };

    y = 100;

    cout << "The result of 4+y = " << increaseByY(x) << endl;
}

enum Color
{
    Red,
    Green,
    Blue
};

enum class GameState : short
{
    Win = 1,
    Lose = 5
};

void enums()
{
    Color c = Red;
    int i = c;

    GameState gs = GameState::Win;
}

union Data
{
    int integer;
    float fpnumber;
    char* text;
};

int FunctionsAndVariables()
{
    functions_and_vars();
    stack_and_heap();
    add(5, 6);
    char * argv[] = { "hello", "allo" };
    functions(argv);
    lambdas();
    enums();
    return 0;
}