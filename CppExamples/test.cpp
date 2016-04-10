#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
int mainTest()
{
    return 1;
    setlocale(LC_ALL, "en_US.UTF-8");
    std::istringstream in("$1,234.56 2.22  3.33 2 200");
    std::istringstream x("123.23 123. 123321.11 123123123.1 123.232");
    long double v1, v2, v4, v5;
    std::string v3;
    //    in.imbue(std::locale("en_US.UTF-8"));
    in >> std::get_money(v1);
    in >> std::get_money(v2);
    in >> std::get_money(v4) >> std::get_money(v5);

    std::cout << '"' << in.str() << "\" parsed as: "
        << v1 << ", " << v2 << ", " << v4 << ", " << v5 << '\n';
}