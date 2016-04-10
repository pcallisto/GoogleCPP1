#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int mainMemory() {
    const static int strSize = 1024;
    const char * source = "This is a string";
    char * string5 = NULL;	// pointer for allocated memory

    printf("Allocating space for string.\n");
    string5 = malloc(strSize * sizeof(char));
    if (string5 == NULL) {
        fputs("cannot allocate memory\n", stderr);
        return 1;
    }

    strncpy(string5, source, strSize);
    printf("The string is: %s\n", string5);

    printf("Freeing string space.\n");
    free(string5);
    string5 = NULL;	// not necessary, but a good idea

    return 0;
}