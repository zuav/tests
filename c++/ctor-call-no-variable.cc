#include <iostream>
#include <string>

class Log {
public:
    enum Level {
        DEBUG,
        INFO
    };

    Log(Level l, const std::string& s)
        {
            std::cout << LEVEL_STR[l] << ' ' << s << std::endl;
        }

private:

    static const char *LEVEL_STR[];
};

const char *Log::LEVEL_STR[] {
    "DEBUG",
    "INFO"
};



int main()
{
    Log(Log::INFO,  "message 1");
    Log(Log::DEBUG, "message 2");

    return 0;
}
