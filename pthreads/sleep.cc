#include <pthread.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "Usage: " << program_invocation_short_name << " sleep_time_in_secs" << std::endl;
        return 1;
    }

    pthread_t tid;

    if (
}
