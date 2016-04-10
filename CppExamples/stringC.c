// string.c by Bill Weinman <http://bw.org/>
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int mainStringC() {
    const static int maxBuf = 128;
    const char * s1 = "String one\n";
    const char * s2 = "String two\n";
    char sd1[128];
    char sd2[128];
    int i = 0;
    char c = 0;
    char * cp = NULL;

    printf("s1 is %s,  s2 is %s\n", s1, s2);
    printf("s1 is %d bytes long", strlen(s1));
    strncpy_s(sd1, maxBuf, s1, strlen(s1));	// strncpy -- copy a string
    printf("sd1 is %s\n", sd1);
    strncpy_s(sd2, maxBuf, s2, strlen(s2));
    printf("sd2 is %s\n", sd2);

    strncat(sd1, " - ", maxBuf - strlen(sd1) - 1);	// strncat -- concatenate string
    strncat(sd1, s2, maxBuf - strlen(sd1) - 1);
    printf("sd1 is %s\n", sd1);

    //	printf("length of sd1 is %ld\n", strlen(sd1));	// strlen -- get length of string
    printf("length of sd2 is %d\n", (int)strlen(sd2));

    i = strcmp(sd1, sd2);	// strcmp -- compare strings
    printf("sd1 %s sd2 (%d)\n", (i == 0) ? "==" : "!=", i);
    i = strcmp(sd2, s2);
    printf("sd2 %s s2 (%d)\n", (i == 0) ? "==" : "!=", i);

    c = 'g';
    cp = strchr(sd1, c);	// strchr -- find a char in string
    printf("Did we find a '%c' in sd1? %s\n", c, cp ? "yes" : "no");

    cp = strstr(sd1, s2);	// strstr -- find a string in string
    printf("Did we find '%s' in sd1? %s\n", s2, cp ? "yes" : "no");
    if (cp) printf("The first '%s' in sd1 is at position %d\n", s2, (int)(cp - sd1));

    return 0;
}