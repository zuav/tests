#include <pthread.h>
#include <string.h>
#include <iostream>


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


int main(int argc, char *argv[])
{
    int rc = pthread_mutex_lock(&mutex);
    if (rc != 0) {
        std::cout << "error locking mutex: " << rc << "; system message: " << strerror(rc) << std::endl;
        return 1;
    }

    rc = pthread_mutex_unlock(&mutex);
    if (rc != 0) {
        std::cout << "error (1) unlocking mutex: " << rc << "; system message: " << strerror(rc) << std::endl;
        return 1;
    }

    rc = pthread_mutex_unlock(&mutex);
    if (rc != 0) {
        std::cout << "error (2) unlocking mutex: " << rc << "; system message: " << strerror(rc) << std::endl;
        return 1;
    }

    return 0;
}
