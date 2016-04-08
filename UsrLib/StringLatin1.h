#pragma once
#include <string>

class StringLatin1
    : public std::string
{
public:
    StringLatin1() {}
    StringLatin1(const std::string & str) : std::string(str) {}
    StringLatin1(const char * str) : std::string(str) {}
    //    StringLatin1(const char str[] ) : std::string(str) {}

    const StringLatin1 ToUpperCase() const;
    const StringLatin1 ToLowerCase() const;
    const StringLatin1 Trimmed() const;
    bool IsEmpty() const;
};
