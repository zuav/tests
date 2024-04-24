#include <atomic>

struct S {
    int i;
    double d;
};



int main()
{
    S s1;

    std::atomic<S *> ps { &s1 };

    // ps->i = 2;

    // return ps->i;

    S *ps1 = ps.load();
    ps1->i = 0;

    return ps1->i;
}
