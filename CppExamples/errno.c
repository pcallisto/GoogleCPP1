// errno.c by Bill Weinman <http://bw.org/>
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <errno.h>
#include <string.h>

int mainErrno() {
    errno = 2226;
    printf("errno is: %d\n", errno);
    printf("Erasing file foo.bar\n");
    remove("foo.bar");
    printf("errno is: %d\n", errno);
    printf("the error message is: %s\n", strerror(errno));
    perror("Couldn't erase file"); // prints text +strerror string
    return 0;
}