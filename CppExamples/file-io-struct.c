// file-io-struct.c by Bill Weinman <http://bw.org/>
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "file-io-struct.h"

int fileIoStruct() {
    const char * fn = "test.file";			// file name
    const char * str = "This is a literal C-string.\n";

    // create/write the file
    printf("writing file\n");
    FILE * fw = fopen(fn, "wb");

    struct s1 buf1;
    for (int i = 0; i < 5; i++) {
        buf1.a = i;
        buf1.b = (uint8_t)strlen(str);
        strncpy(buf1.s, str, slen);
        fwrite(&buf1, sizeof(struct s1), 1, fw);
    }

    fclose(fw);
    printf("done.\n");

    // read the file
    printf("reading file\n");
    FILE * fr = fopen(fn, "rb");
    struct s1 buf2;
    int rc;
    while ((rc = fread(&buf2, sizeof(struct s1), 1, fr))) {
        printf("a: %d, b: %d, s: %s", buf2.a, buf2.b, buf2.s);
    }

    fclose(fr);
    printf("done.\n");

    //----------------------------------------------------------------------

    printf("\n\nCalling a C++ member function...\n");

    int j = 0;
    struct M;                           // you can supply only an incomplete declaration
    int call_M_foo(struct M*, int);     // declare the wrapper function
    int call_M_poo(struct M*, int);     // declare the wrapper function
    void call_M_setI(struct M*, int);
    int call_M_getI(struct M*);
    struct M* p;
    struct M* p2;
    call_M_foo(p = 0, j);
    call_M_poo(p2 = 0, j);
    call_M_setI(&p, 5);
    printf("GetI from cpp's classM returned: %d", call_M_getI(&p));
    const char * fn1 = "file1";
    const char * fn2 = "file2";
    const char * fn3 = "file3";
    const char * fn4 = "file4";
    FILE * fh1 = fopen(fn1, "w");
    FILE * fh2 = fopen(fn1, "w");
    fclose(fh1);
    fclose(fh2);
    printf("\n\n[Files created|...");
    int k = 0;
    k = rename(fn1, fn3);
    k += rename(fn2, fn4);
    printf("files renamed|...");
    remove(fn3);
    remove(fn4);
    printf("and files are removed]\n");
    puts("Puts adds");
    puts("newlines");
    puts("   automatically");
    fputs("On the otherhand ", stdout);
    fputs("fputs does not ", stdout);
    fputs("write the newline. So we must add it here ->\n", stdout);

    FILE * out = fopen("file.txt", "w");
    fputs("This tring was written to a file.\n", out);
    fclose(out);

    char s[128];
    FILE * in = fopen("file.txt", "r");
    fgets(s, sizeof(s), in);
    fclose(in);
    printf(s);

    int i = 5;
    long int li = 1234567890L;
    char * s2 = "This is a string";
    fprintf(stdout, "\ni is  %d li is %ld, s2 is %s\n", i, li, s2);
    fprintf(stderr, "\ni is  %d li is %ld, s2 is %s\n", i, li, s2);
    FILE * in2 = fopen("file.txt", "w");
    fprintf(in2, "\ni is  %d li is %ld, s2 is %s\n", i, li, s2);
    fclose(in2);
    system("type file.txt");
    const int bufsize = 128;
    char os[128];
    k += snprintf(os, bufsize, "\nsprintf'd; i is  %d li is %d, s2 is %s\n", i, li, s2);
    puts(os);

    return 0;
}