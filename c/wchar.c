#include <string.h>
#include <wchar.h>
#include <stdio.h>

#define WBUF_SIZE 1024

int main()
{
    wchar_t wc;
    wchar_t wbuf[WBUF_SIZE];
    size_t wcsz = sizeof wc;

    printf("wc size:   %zd\n", wcsz);
    printf("wbuf size: %zd\n", sizeof wbuf);

    /* #define DO_WPRINTF_TEST(n,  check,     fmt,    ...) \ */
    /*         DO_WPRINTF_TEST(33, "1.2e+04", "%.2g", 12345.6789); */

    memset(wbuf, 0, sizeof wbuf);

    if (swprintf(wbuf, WBUF_SIZE, L"%.2g", 12345.6789) != wcslen(L"1.2e+04")) {
        printf("FAIL! wbuf is \"%ls\", but expected \"%ls\"\n", wbuf, L"1.2e+04");
        return 1;
    }

    printf("wbuf:      %ls\n", wbuf);

    if (wcscmp(wbuf, L"1.2e+04") != 0) {
        printf("FAIL! wbuf is \"%ls\", but expected \"%ls\"\n", wbuf, L"1.2e+04");
        return 1;
    }


    /* #define DO_WPRINTF_TEST(n,  check,                  fmt,  ...) \ */
    /*         DO_WPRINTF_TEST(34, "0x1.edd3c07fb400bp+6", "%a", 123.4567890123); */

    memset(wbuf, 0, sizeof wbuf);

    if (swprintf(wbuf, WBUF_SIZE, L"%a", 123.4567890123) != wcslen(L"0x1.edd3c07fb400bp+6")) {
        printf("FAIL! wbuf is \"%ls\", but expected \"%ls\"\n", wbuf, L"0x1.edd3c07fb400bp+6");
        return 1;
    }

    printf("wbuf:      %ls\n", wbuf);

    if (wcscmp(wbuf, L"0x1.edd3c07fb400bp+6") != 0) {
        printf("FAIL! wbuf is \"%ls\", but expected \"%ls\"\n", wbuf, L"0x1.edd3c07fb400bp+6");
        return 1;
    }


    return 0;
}
