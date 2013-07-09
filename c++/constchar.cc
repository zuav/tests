int main()
{
    char buf[] = "abcdef";
    const char *p = buf;

    buf[0] = buf[1];
    p[0] = p[1];

    return 0;
}
