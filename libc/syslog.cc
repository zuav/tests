#include <errno.h>
#include <syslog.h>



int main()
{
    const char *mlt =
        "Tries:           Nodes        Containers   Size\n"
        "---------------  ------------ ------------ ------------\n"
        "  Group Digits             50            1        98304\n"
        "       NumTrie             73            1       130968\n"
        "  Account Digits            0            0            0\n"
        "       NumTrie             33            1       130968\n"
        "  Accounts                 24            1        98304\n"
        "  Route Groups             89            1        98304\n"
        "  Device Groups           120            1        98304\n"
        "  Device Trunks           190            1        98304\n"
        "  Time Zones               83            1        98304\n"
        "---------------  ------------ ------------ ------------\n"
        "  Total                                          851760\n";

    openlog(program_invocation_short_name, LOG_PID|LOG_NDELAY, LOG_USER);

    syslog(LOG_ERR, "this is an error message: %s", "some error text");
    syslog(LOG_WARNING, "this is a warning message: %s", "some warning text");
    syslog(LOG_INFO, "this is a info message: %s", "some info text");
    syslog(LOG_INFO, "this is a multi-line info message:\n%s", mlt);

    return 0;
}
