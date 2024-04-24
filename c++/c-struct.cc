#include <netinet/in.h>

int main()
{
    uint16_t port = 1234;
    sockaddr_in name;

    name.sin_family = AF_INET;
    name.sin_port = htons(port);

    return 0;
}
