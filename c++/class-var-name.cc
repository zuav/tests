#include <iostream>


struct jid {
    jid() : i(57) {}

    int i;
};


int main(int argc, char *argv[])
{
    jid jid;

    std::cout << "jid: " << jid.i << std::endl;

    return 0;
}
