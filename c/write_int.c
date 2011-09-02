#include <fcntl.h>
#include <unistd.h>

int main()
{
    int h = open("/tmp/zzz2.bin", O_WRONLY|O_CREAT|O_TRUNC, 0660);
    int v = 50;

    write(h, &v, sizeof(v));
    close(h);

    return 0;
}
