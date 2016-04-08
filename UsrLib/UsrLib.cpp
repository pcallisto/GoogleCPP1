#pragma once
#include "stdafx.h"
#include "UsrLib.h"

#include <iostream>

Int32 ConvertAsciiToInt32(const char * str, UInteger len)
{
    Int32 value = 0;

    const char * endStr = str + len;

    int neg = false;
    if (*str == '-')
    {
        neg = true;
        str++;
    }

    while (str != endStr)
    {
        char ch = *str++;
        if (!isdigit(ch))
            break;

        value = value * 10 + (ch - '0');
    }

    if (neg)
        value = -value;

    return value;
}

//-----------------------------------------------------------------------------
Int64 ConvertAsciiToInt64(const char * str, UInteger len)
{
    Int64 value = 0;

    const char * endStr = str + len;

    int neg = false;
    if (*str == '-')
    {
        neg = true;
        str++;
    }

    while (str != endStr)
    {
        char ch = *str++;
        if (!isdigit(ch))
            break;

        value = value * 10 + (ch - '0');
    }

    if (neg)
        value = -value;

    return value;
}