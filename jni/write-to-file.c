#include <stdlib.h>
#include <stdio.h>
#include "write-to-file.h"

int write_to_file(const char *filename, const char *str, int code)
{
    int rc = 0;
    FILE *f = fopen(filename, "a");

    if (!f)
        return 1;

    rc = fprintf(f, "%s: %d\n", str, code);
    if (rc < 0)
        return 2;

    fclose(f);

    return 0;
}


#ifdef MAIN

int main()
{
    int i = 0;
    int rc = 0;

    for (i=0; i<10; ++i) {
        rc = write_to_file("/tmp/write-to-file.log", "bla-bla-bla", i);
        if (rc != 0) {
            printf("error: %d\n", rc);
            exit(1);
        }
    }

    return 0;
}

#endif
