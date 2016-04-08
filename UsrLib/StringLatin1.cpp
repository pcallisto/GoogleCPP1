#include "stdafx.h"
#include "StringLatin1.h"

#include <algorithm>
#include <string>

const StringLatin1 StringLatin1::ToUpperCase() const
{
    StringLatin1 result = *this;

    std::transform(result.begin(), result.end(), result.begin(), ::toupper);

    return result;
}

const StringLatin1 StringLatin1::ToLowerCase() const
{
    StringLatin1 result = *this;

    std::transform(result.begin(), result.end(), result.begin(), ::tolower);

    return result;
}
const StringLatin1 StringLatin1::Trimmed() const
{
    int firstPos = 0;
    int endPos = static_cast<int>(length());

    while ((firstPos < endPos) && isspace(at(firstPos)))
        firstPos++;

    while ((firstPos < endPos) && isspace(at(endPos - 1)))
        endPos--;

    return substr(firstPos, endPos - firstPos);
}

bool StringLatin1::IsEmpty() const
{
    if (Trimmed().length() == 0)
        return true;
    return false;
}