#pragma once
#include <limits.h>

#include "BaseTsd.h"

typedef          size_t   UInteger;

#define     UIntegerMax      SIZE_MAX
typedef         SSIZE_T    Integer;
typedef unsigned __int8    Byte;
typedef unsigned __int8   UByte;
typedef unsigned __int16  UInt16;
typedef          __int16   Int16;
typedef unsigned __int32  UInt32;
typedef          __int32   Int32;
typedef unsigned __int64  UInt64;
typedef          __int64   Int64;

//#define Types

inline Integer IntegerAbs(Integer Value) { return Value < 0 ? -Value : Value; }

Int32  ConvertAsciiToInt32(const char * str, UInteger len);
Int64  ConvertAsciiToInt64(const char * str, UInteger len);

enum ECharacterSet
{
    eLatin1CharacterSet,
    eUtf8Characterset
};

enum EDayOfWeek
{
    eUnknownDayOfWeek = -1,
    eSundayDayOfWeek = 0,
    eMondayDayOfWeek,
    eTuesdayDayOfWeek,
    eWednesdayDayOfWeek,
    eThursdayDayOfWeek,
    eFridayDayOfWeek,
    eSaturdayDayOfWeek
};

enum Sex
{
    eMale,
    eFemale
};

typedef Int64 TimeUSecs;
