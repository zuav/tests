#include <errno.h>
#include <stdio.h>
#include <string.h>


static int make_test_file(char *fname);


int main()
{
    char fname[L_tmpnam+1];

    if (make_test_file(fname) != 0) {
        printf("test_getline: failed to make test file\n");
        return 1;
    }

    return 0;
}


int make_test_file(char *fname)
{
    FILE *f;
    int rc, i;

    if (tmpnam(fname) == NULL) {
        printf("test_getline: tmpnam failed\n");
        return 1;
    }

    f = fopen(fname, "w");
    if (f == NULL) {
        rc = errno;
        printf("failed to open temp file; error %i; %s\n", rc, strerror(rc));
        return 1;
    }

    for (i=1; i<3; ++i) {
        if (fprintf(f, "Line%i_1 LineIi_2\n", i) < 0) {
            rc = errno;
            printf("failed to write line %i to temp file; error %i; %s\n", i, rc, strerror(rc));
            return 1;
        }
    }

    if (fclose(f) != 0) {
        rc = errno;
        printf("failed to close temp file; error %i; %s\n", rc, strerror(rc));
        return 1;
    }

    return 0;
}
