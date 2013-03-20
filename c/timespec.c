#include <assert.h>
#include <time.h>
#include <stdio.h>


long long diff(const struct timespec *s, const struct timespec *e);


int main()
{
    struct timespec ts;
    struct timespec te;
    long long nanosecs;
    long long nanodiff;

    printf("sizeof(long)      = %lu\n", sizeof(long));
    printf("sizeof(long long) = %lu\n", sizeof(long long));

    assert(clock_gettime(CLOCK_MONOTONIC, &ts) == 0);

    te = ts;
    te.tv_sec += 3;

    nanosecs = ((long long) ts.tv_sec * 1000000000LL) + ts.tv_nsec;
    nanodiff = diff(&ts, &te);

    printf("ts.tv_sec:  %ld\n",  ts.tv_sec);
    printf("ts.tv_nsec: %ld\n",  ts.tv_nsec);
    printf("nanosecs:   %Ld\n",  nanosecs);
    printf("nanodiff:   %Ld\n",  nanodiff);

    return 0;
}

long long diff(const struct timespec *s, const struct timespec *e)
{
    long long start = ((long long) s->tv_sec * 1000000000LL) + (long long) s->tv_nsec;
    long long end   = ((long long) e->tv_sec * 1000000000LL) + (long long) e->tv_nsec;

    /* printf("DEBUG: start: %Ld\n", start); */
    /* printf("DEBUG: end:   %Ld\n", end); */

    return (end - start) / 1000000;
}
