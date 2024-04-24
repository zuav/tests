#include <errno.h>
#include <string>
#include <iostream>
#include <yaml-cpp/yaml.h>


enum Log_level {
    CRITICAL,
    ERROR,
    WARNING,
    NOTICE,
    INFO,
    DEBUG
};


namespace YAML {
    template<>
    struct convert<Log_level> {
        static Node encode(Log_level rhs)
            {
                const char *str = 0;
                switch (rhs) {
                case CRITICAL:
                    str = "CRITICAL";
                    break;
                case ERROR:
                    str = "ERROR";
                    break;
                case WARNING:
                    str = "WARNING";
                    break;
                case NOTICE:
                    str = "NOTICE";
                    break;
                case INFO:
                    str = "INFO";
                    break;
                case DEBUG:
                    str = "DEBUG";
                    break;
                default:
                    break;
                }

                return YAML::Load(str);
            }

        static bool decode(const Node& node, Log_level& rhs);
    };
}


//template<>
bool YAML::convert<Log_level>::decode(const Node& node, Log_level& rhs)
{
    if (!node.IsScalar()) {
        return false;
    }

    const std::string str = node.as<std::string>();
    if (str == "DEBUG") {
        rhs = Log_level::DEBUG;
        return true;
    }

    return false;
}



int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << program_invocation_short_name << " yaml-file-name" << std::endl;
        return 1;
    }

    try {
        std::string fname = argv[1];

        std::cout << "loading file: " << fname << std::endl;
        YAML::Node config = YAML::LoadFile(fname);

        YAML::Node global = config["global"];
        if (!global)
            std::cerr << "ERROR: config file must contain part with key name: global" << std::endl;
        else
            std::cout << "global section is present" << std::endl;

        // Log_level ll = global["log_level"].as<Log_level>();

        // std::string ll1 = global["log_level_1"].as<std::string>();
        // std::cout << "ll1 = '" << ll1 << "'" << std::endl;

        YAML::Node route = config["route"];
        if (route)
            std::cout << "route section is present" << std::endl;
        else
            std::cout << "route section is NOT present" << std::endl;

        YAML::Node route2 = route[1];
        if (route2)
            std::cout << "second route is present" << std::endl;
        else
            std::cout << "second route is NOT present" << std::endl;

        YAML::Node input = route2["input"];
        if (input)
            std::cout << "input in second route is present" << std::endl;
        else
            std::cout << "input in second route is is NOT present" << std::endl;

        YAML::Node stream = input[0];
        if (stream)
            std::cout << "first stream in input in second route is present" << std::endl;
        else
            std::cout << "first stream input in second route is is NOT present" << std::endl;

        YAML::Node link = stream["link"];
        if (link)
            std::cout << "link in input in second route is present" << std::endl;
        else
            std::cout << "link in input in second route is NOT present" << std::endl;

        YAML::Node link0 = link[0];
        if (link0)
            std::cout << "link[0] in input in second route is present" << std::endl;
        else
            std::cout << "link[0] in input in second route is NOT present" << std::endl;

        YAML::Node host = link0["host"];
        if (host)
            std::cout << "host in link[0] in input in second route is present" << std::endl;
        else
            std::cout << "host in link[0] in input in second route is NOT present" << std::endl;

        if (host.IsNull())
            std::cout << "host value is empty" << std::endl;

        std::cout << "host = '" << host.as<std::string>() << "'" << std::endl;

        // std::cout << "printing content: " << std::endl
        //           << config
        //           << std::endl;
    }
    catch (std::exception& exc) {
        std::cerr << "error: " << exc.what() << std::endl;
        return 2;
    }

    return 0;
}
