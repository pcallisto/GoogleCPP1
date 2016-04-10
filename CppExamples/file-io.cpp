// file-io.c by Bill Weinman <http://bw.org/>
#include <stdio.h>

int fileIo() {
    const char * fn = "test.file";			// file name
    const static int maxString = 1024;	// read buffer size
    const char * str = "This is a literal C-string.\n";

    // create/write the file
    printf("writing file\n");
    //	FILE * fw = fopen(fn, "w");
    FILE *fw;
    int errno_t = fopen_s(&fw, fn, "w");
    if (errno_t) {
        printf("Error: couldn't open file");
    }
    if (fw != 0) {
        for (int i = 0; i < 5; i++) {
            fputs(str, fw);
        }
        fclose(fw);
        printf("done.\n");
    }
    // read the file
    printf("reading file\n");
    char buf[maxString];
    FILE * fr;
    char * rc;
    if (fopen_s(&fr, fn, "r") == 0)  //fopen is deprecated
    {
        printf("Error: can't open file in readonly mode");
    }
    if (fr != 0)
    {
        while ((rc = fgets(buf, maxString, fr)))
        {
            printf(buf);
        }

        fclose(fr);
        printf("done.\n");
    }
    return 0;
}