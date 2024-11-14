#include <string.h>
#include <iostream>
#include <chrono>



struct S {
    int a;
    short b;
    long c;
    double d;
    char uuid[16];

    S();
};

S::S()
    : a(0),
      b(0),
      c(0),
      d(0.0)
{
    memset(uuid, 0, sizeof(uuid));
}


static S counter_by_value;
static S counter_by_reference;


static void copy_by_value();
static void copy_by_reference();
static S get_new_s();
static void get_new_s(S&);



int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "Usage: " << program_invocation_short_name << " num-iterations" << std::endl;
        return 1;
    }

    int num = strtol(argv[1], 0, 0);

    auto start0 = std::chrono::high_resolution_clock::now();
    for (int i=0; i<num; ++i)
        copy_by_value();
    auto end0 = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds diff0 = end0 - start0;
    std::cout << "copy by value:       " << diff0.count() << std::endl;

    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i=0; i<num; ++i)
        copy_by_reference();
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds diff1 = end1 - start1;
    std::cout << "copy by reference:   " << diff1.count() << std::endl;

    return 0;
}


void copy_by_value()
{
    S s = get_new_s();

    counter_by_value.a += s.a;
    counter_by_value.b += s.b;
    counter_by_value.c += s.c;
    counter_by_value.d += s.d;

    for (int i=0; i<16; ++i)
        counter_by_value.uuid[i] += s.uuid[i];
}


void copy_by_reference()
{
    S s;
    get_new_s(s);

    counter_by_value.a += s.a;
    counter_by_value.b += s.b;
    counter_by_value.c += s.c;
    counter_by_value.d += s.d;

    for (int i=0; i<16; ++i)
        counter_by_reference.uuid[i] += s.uuid[i];
}


S get_new_s()
{
    S s;

    s.a++;
    s.b++;
    s.c++;
    s.d++;

    for (int i=0; i<16; ++i)
        s.uuid[i]++;

    return s;
}


void get_new_s(S& s)
{
    s.a++;
    s.b++;
    s.c++;
    s.d++;

    for (int i=0; i<16; ++i)
        s.uuid[i]++;
}
