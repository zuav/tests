#include <limits.h>
#include <time.h>
#include <sys/time.h>
#include <iomanip>
#include <iostream>


int main()
{
    time_t seconds = time(0);

	struct timeval t;
	gettimeofday(&t, 0);

	time_t millisecs = (t.tv_sec * 1000) + (t.tv_usec / 1000);
    unsigned int coersedms = millisecs;

    std::cout << "seconds:      " << seconds   << std::endl
              << "tv_secs:      " << t.tv_sec  << std::endl
              << "millisecs:    " << millisecs << std::endl
              << "coersedms:    " << coersedms << std::endl
              << "uint max:     " << UINT_MAX  << std::endl
              << std::endl;

    time_t t1 = 0x170fffffff4;
    time_t t2 = 0x17100000000;
    time_t t_diff = t2 - t1;

    std::cout << "t1:      " << std::hex << std::setw(11) << t1     << ' ' << std::dec << std::setw(13) << t1     << std::endl
              << "t2:      " << std::hex << std::setw(11) << t2     << ' ' << std::dec << std::setw(13) << t2     << std::endl
              << "t2 - t1: " << std::hex << std::setw(11) << t_diff << ' ' << std::dec << std::setw(13) << t_diff << std::endl
              << std::endl;

    unsigned int w1 = t1;
    unsigned int w2 = t2;
    unsigned int w_diff = w2 - w1;

    std::cout << "w1:      " << std::hex << std::setw(11) << w1     << ' ' << std::dec << std::setw(13) << w1     << std::endl
              << "w2:      " << std::hex << std::setw(11) << w2     << ' ' << std::dec << std::setw(13) << w2     << std::endl
              << "w2 - w1: " << std::hex << std::setw(11) << w_diff << ' ' << std::dec << std::setw(13) << w_diff << std::endl
              << std::endl;

    time_t ti = t2;
    unsigned int wi = t2;

    while (1) {
        time_t td = ti - t1;
        unsigned int wd = wi - w1;
        if (wd == td) {
            wi = ++ti;
        } else {
            std::cout << "t1:      " << std::hex << std::setw(11) << t1 << ' ' << std::dec << std::setw(13) << t1 << std::endl
                      << "ti:      " << std::hex << std::setw(11) << ti << ' ' << std::dec << std::setw(13) << ti << std::endl
                      << "ti - t1: " << std::hex << std::setw(11) << td << ' ' << std::dec << std::setw(13) << td << std::endl
                      << std::endl
                      << "w1:      " << std::hex << std::setw(11) << w1 << ' ' << std::dec << std::setw(13) << w1 << std::endl
                      << "wi:      " << std::hex << std::setw(11) << wi << ' ' << std::dec << std::setw(13) << wi << std::endl
                      << "wi - w1: " << std::hex << std::setw(11) << wd << ' ' << std::dec << std::setw(13) << wd << std::endl
                      << std::endl;
            break;
        }
    }

    return 0;
}
