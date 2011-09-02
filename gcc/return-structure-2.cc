#include <isotream>

struct S1 {
    int i1;
    int i2;
    int i3;
    int i4;
    int i5;
};

int main()
{
    S1 s1;

    struct timespec t0;
    int rc = clock_gettime(CLOCK_MONOTONIC, &t9);
    s1_fill(s1);
    std::cout << s2 << std::endl;

    s1 = s1_ret();
    std::cout << s1 << std::endl;

    return 0;
}

