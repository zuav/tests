#include <wchar.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

int main()
{
    wchar_t wbuf[BUF_SIZE];
    int len;

    memset(wbuf, 0, sizeof wbuf);
    len = swprintf(wbuf, BUF_SIZE, L"%ls", "abcd");
    printf("len: %d; wbuf len: %Zd, wbuf: %ls\n", len, wcslen(wbuf), wbuf);
    printf("\n");

    memset(wbuf, 0, sizeof wbuf);
    len = swprintf(wbuf, BUF_SIZE, L"%ls", L"abcd");
    printf("len: %d; wbuf len: %Zd, wbuf: %ls\n", len, wcslen(wbuf), wbuf);

    return 0;
}
