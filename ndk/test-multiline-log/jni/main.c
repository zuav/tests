#include <string.h>
#include <android/log.h>


int main()
{
    const char *m1 = "message 1";
    const char *m2 = "message 2";
    const char *m3 = "message 3";

    __android_log_print(ANDROID_LOG_INFO, "MULTILINE_LOG",  "m1: %s;\nm2: %s;\nm3: %s;", m1, m2, m3);

    return 0;
}
