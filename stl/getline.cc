#include <iostream>


int sig_flag = 0;


void sighandler(int)
{
    sig_flag = 1;
}

int main()
{
	::signal(SIGINT, &sighandler);

    while (!stop) {
        std::string line;
        std::getline(std::cin, line);
    }

    return 0;
}
