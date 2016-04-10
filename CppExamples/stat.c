// stat.c by Bill Weinman <http://bw.org/>
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include "CppExamples.h"

int mainStat() {
    const char * fname = "file.txt";
    struct stat fstat;

    if (stat(fname, &fstat) == 0) {
        fprintf(stdout, "Name: %s, UID: %u, GID: %u, Size: %ld\n",
            fname, fstat.st_uid, fstat.st_gid, fstat.st_size);

        // file modification time is in seconds since midnite 1970-01-01 UTC
        const int bufSize = 128;
        char buf[128];
        // struct tm mtime = *gmtime(&fstat.st_mtimespec.tv_sec);
        struct tm mtime = *gmtime(&fstat.st_mtime);
        strftime(buf, bufSize, "%Y-%m-%d %H:%M:%S %Z", &mtime);
        printf("Last modified: %s\n", buf);
    }
    else {
        perror("Couldn't stat file");
    }
    return 0;
}