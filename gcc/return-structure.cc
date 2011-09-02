#include <errno.h>
#include <error.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
// #include <iostream>
// #include <string>


// struct Small {
//     std::string sm1;
//     std::string sm2;
// };

// struct Big {
//     std::string sm01;
//     std::string sm02;
//     std::string sm03;
//     std::string sm04;
//     std::string sm05;
//     std::string sm06;
//     std::string sm07;
//     std::string sm08;
//     std::string sm09;
//     std::string sm10;
//     std::string sm11;
//     std::string sm12;
//     std::string sm13;
//     std::string sm14;
//     std::string sm15;
//     std::string sm16;
//     std::string sm17;
//     std::string sm18;
//     std::string sm19;
//     std::string sm20;
// };

typedef struct {
    int i0;
    int i1;
    int i2;
    int i3;
    int i4;
    int i5;
    int i6;
    int i7;
    int i8;
    int i9;
} Int;

// void test_fill_small(int);
// void test_copy_small(int);
// void test_fill_big  (int);
// void test_copy_big  (int);
void test_fill_int  (int);
void test_copy_int  (int);

// void  fill_small(Small&);
// Small copy_small();

// void fill_big(Big&);
// Big  copy_big();

void fill_int(Int*);
Int  copy_int();

struct timespec delta(struct timespec, struct timespec);


int main(int argc, char *argv[])
{
    // if (argc != 2) {
    //     std::cerr << "Usage: " << program_invocation_short_name << " number" << std::endl;
    //     return 100;
    // }

    int numtries = strtol(argv[1], 0, 0);

    struct timespec fillint;
    struct timespec copyint;

    // // fill small (t2 - t1)
    // struct timespec t1;
    // int rc = clock_gettime(CLOCK_MONOTONIC, &t1);
    // if (rc != 0) error(1, rc, "cant' get clock time");
    // test_fill_small(numtries);
    // struct timespec t2;
    // rc = clock_gettime(CLOCK_MONOTONIC, &t2);
    // if (rc != 0) error(2, rc, "cant' get clock time");

    // // copy small (t4 - t3)
    // struct timespec t3;
    // rc = clock_gettime(CLOCK_MONOTONIC, &t3);
    // if (rc != 0) error(3, rc, "cant' get clock time");
    // test_copy_small(numtries);
    // struct timespec t4;
    // rc = clock_gettime(CLOCK_MONOTONIC, &t4);
    // if (rc != 0) error(4, rc, "cant' get clock time");

    // // fill big (t6 - t5)
    // struct timespec t5;
    // rc = clock_gettime(CLOCK_MONOTONIC, &t5);
    // if (rc != 0) error(5, rc, "cant' get clock time");
    // test_fill_big(numtries);
    // struct timespec t6;
    // rc = clock_gettime(CLOCK_MONOTONIC, &t6);
    // if (rc != 0) error(6, rc, "cant' get clock time");

    // // copy big (t8 - t7)
    // struct timespec t7;
    // rc = clock_gettime(CLOCK_MONOTONIC, &t7);
    // if (rc != 0) error(7, rc, "cant' get clock time");
    // test_copy_big(numtries);
    // struct timespec t8;
    // rc = clock_gettime(CLOCK_MONOTONIC, &t8);
    // if (rc != 0) error(8, rc, "cant' get clock time");

    // fill int (t10 - t9)
    struct timespec t9;
    int rc = clock_gettime(CLOCK_MONOTONIC, &t9);
    if (rc != 0) error(9, rc, "cant' get clock time");
    test_fill_int(numtries);
    struct timespec t10;
    rc = clock_gettime(CLOCK_MONOTONIC, &t10);
    if (rc != 0) error(10, rc, "cant' get clock time");

    // copy int (t12 - t11)
    struct timespec t11;
    rc = clock_gettime(CLOCK_MONOTONIC, &t11);
    if (rc != 0) error(11, rc, "cant' get clock time");
    test_copy_int(numtries);
    struct timespec t12;
    rc = clock_gettime(CLOCK_MONOTONIC, &t12);
    if (rc != 0) error(12, rc, "cant' get clock time");

    // struct timespec fillsmall = delta(t2, t1);
    // struct timespec copysmall = delta(t4, t3);

    // struct timespec fillbig = delta(t6, t5);
    // struct timespec copybig = delta(t8, t7);

    fillint = delta(t10, t9);
    copyint = delta(t12, t11);

    // std::cout << "fill small: " << fillsmall.tv_sec << ':' << fillsmall.tv_nsec << std::endl
    //           << "copy small: " << copysmall.tv_sec << ':' << copysmall.tv_nsec << std::endl
    //           << std::endl
    //           << "fill big: " << fillbig.tv_sec << ':' << fillbig.tv_nsec << std::endl
    //           << "copy big: " << copybig.tv_sec << ':' << copybig.tv_nsec << std::endl
    //           << std::endl
    //           << "fill int: " << fillint.tv_sec << ':' << fillint.tv_nsec << std::endl
    //           << "copy int: " << copyint.tv_sec << ':' << copyint.tv_nsec << std::endl;

    printf("fill int: %d:%d\n", fillint.tv_sec, fillint.tv_nsec);
    printf("copy int:  %d:%d\n", copyint.tv_sec, copyint.tv_nsec);


    return 0;
}

// void test_fill_small(int num)
// {
//     for (int i=0; i<num; ++i) {
//         Small v;
//         fill_small(v);
//         v.sm1 = "q1";
//         v.sm2 = "q2";
//     }
// }

// void test_copy_small(int num)
// {
//     for (int i=0; i<num; ++i) {
//         Small v = copy_small();
//         v.sm1 = "qq";
//         v.sm2 = "qq";
//     }
// }

// void test_fill_big(int num)
// {
//     for (int i=0; i<num; ++i) {
//         Big v;
//         fill_big(v);
//         v.sm01 = "qq";
//         v.sm02 = "qq";
//         v.sm03 = "qq";
//         v.sm04 = "qq";
//         v.sm05 = "qq";
//         v.sm06 = "qq";
//         v.sm07 = "qq";
//         v.sm08 = "qq";
//         v.sm09 = "qq";
//         v.sm10 = "qq";
//         v.sm11 = "qq";
//         v.sm12 = "qq";
//         v.sm13 = "qq";
//         v.sm14 = "qq";
//         v.sm15 = "qq";
//         v.sm16 = "qq";
//         v.sm17 = "qq";
//         v.sm18 = "qq";
//         v.sm19 = "qq";
//         v.sm20 = "qq";
//     }
// }

// void test_copy_big(int num)
// {
//     for (int i=0; i<num; ++i) {
//         Big v = copy_big();
//         v.sm01 = "qq";
//         v.sm02 = "qq";
//         v.sm03 = "qq";
//         v.sm04 = "qq";
//         v.sm05 = "qq";
//         v.sm06 = "qq";
//         v.sm07 = "qq";
//         v.sm08 = "qq";
//         v.sm09 = "qq";
//         v.sm10 = "qq";
//         v.sm11 = "qq";
//         v.sm12 = "qq";
//         v.sm13 = "qq";
//         v.sm14 = "qq";
//         v.sm15 = "qq";
//         v.sm16 = "qq";
//         v.sm17 = "qq";
//         v.sm18 = "qq";
//         v.sm19 = "qq";
//         v.sm20 = "qq";
//     }
// }

void test_fill_int(int num)
{
    int i = 0;
    for (i=0; i<num; ++i) {
        Int v;
        fill_int(&v);
    }
}

void test_copy_int(int num)
{
    int i = 0;
    for (i=0; i<num; ++i) {
        Int v = copy_int();
    }
}

// void fill_small(Small& v)
// {
//     v.sm1 = "small one";
//     v.sm2 = "small two";
// }

// Small copy_small()
// {
//     Small v;
//     v.sm1 = "small one";
//     v.sm2 = "small two";

//     return v;
// }

// void fill_big(Big& v)
// {
//     v.sm01 = "small one";
//     v.sm02 = "small two";
//     v.sm03 = "small three";
//     v.sm04 = "small four";
//     v.sm05 = "small five";
//     v.sm06 = "small six";
//     v.sm07 = "small seven";
//     v.sm08 = "small eight";
//     v.sm09 = "small nine";
//     v.sm10 = "small ten";
//     v.sm11 = "small eleven";
//     v.sm12 = "small twelve";
//     v.sm13 = "small thirteen";
//     v.sm14 = "small fourteen";
//     v.sm15 = "small fifteen";
//     v.sm16 = "small sixteen";
//     v.sm17 = "small seventeen";
//     v.sm18 = "small eighteen";
//     v.sm19 = "small nineteen";
//     v.sm20 = "small twenty";
// }

// Big copy_big()
// {
//     Big v;
//     v.sm01 = "small one";
//     v.sm02 = "small two";
//     v.sm03 = "small three";
//     v.sm04 = "small four";
//     v.sm05 = "small five";
//     v.sm06 = "small six";
//     v.sm07 = "small seven";
//     v.sm08 = "small eight";
//     v.sm09 = "small nine";
//     v.sm10 = "small ten";
//     v.sm11 = "small eleven";
//     v.sm12 = "small twelve";
//     v.sm13 = "small thirteen";
//     v.sm14 = "small fourteen";
//     v.sm15 = "small fifteen";
//     v.sm16 = "small sixteen";
//     v.sm17 = "small seventeen";
//     v.sm18 = "small eighteen";
//     v.sm19 = "small nineteen";
//     v.sm20 = "small twenty";

//     return v;
// }

void fill_int(Int *v)
{
    v->i0 = 0;
    v->i1 = 1;
    v->i2 = 2;
    v->i3 = 3;
    v->i4 = 4;
    v->i5 = 5;
    v->i6 = 6;
    v->i7 = 7;
    v->i8 = 8;
    v->i9 = 9;
}

Int copy_int()
{
    Int v;
    v.i0 = 0;
    v.i1 = 1;
    v.i2 = 2;
    v.i3 = 3;
    v.i4 = 4;
    v.i5 = 5;
    v.i6 = 6;
    v.i7 = 7;
    v.i8 = 8;
    v.i9 = 9;

    return v;
}

struct timespec delta(struct timespec t2, struct timespec t1)
{
    struct timespec r;

    r.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    if (r.tv_nsec < 0) {
        r.tv_nsec += 1000000000;
        t2.tv_sec -= 1;
    }

    r.tv_sec = t2.tv_sec - t1.tv_sec;

    return r;
}
