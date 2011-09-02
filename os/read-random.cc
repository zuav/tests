#include <errno.h>
#include <error.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <iomanip>

int main(int argc, char *argv[])
{
    if (argc != 2)
        error(EXIT_FAILURE, 0, "Usage: read-radnom number_of_bytes");

    int num = strtol(argv[1], 0, 0);

    int h = open("/dev/random", O_RDONLY);
    if (h == -1)
        error(EXIT_FAILURE, errno, "can not open /dev/random");

    unsigned char *buf = new unsigned char[num];
    if (!buf)
        error(EXIT_FAILURE, 0, "can not allocate %d bytes", num);
    memset(buf, 0, num);

    int rc = read(h, buf, num);
    if (rc != num)
        error(EXIT_FAILURE, errno, "can not read %d bytes", num);

    std::ostringstream os;
    for (int i=0; i<num; ++i)
        os << std::setfill('0') << std::hex << std::setw(2) << unsigned(buf[i]);

    std::cout << os.str() << std::endl;

    return 0;
}
