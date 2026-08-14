#include <errno.h>
#include <string>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>


using json = nlohmann::json;



int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << program_invocation_short_name << " json-file-name" << std::endl;
        return 1;
    }

    try {
        std::string fname = argv[1];

        std::cout << "loading file: " << fname << std::endl;
        std::ifstream is(fname);
        json data = json::parse(is);

        json global = data["global"];
        if (global.is_null())
            std::cerr << "ERROR: config file must contain part with key name: global" << std::endl;
        else
            std::cout << "global section is present" << std::endl;

        std::string loglevel = global["log_level"].get<std::string>();
        std::cout << "global.log_level: " << loglevel << std::endl;

        json routes = data["route"];
        if (routes.is_null()) {
            std::cout << "route section is NOT present" << std::endl;
            exit(3);
        }
        if (!routes.is_array()) {
            std::cout << "route section is NOT array" << std::endl;
            exit(3);
        }

        std::cout << "route section has " << routes.size() << " elements:" << std::endl;
        for (const auto& r : routes) {
            std::string name = r["name"].get<std::string>();
            std::cout << "  " << name << std::endl;
        }

        // Log_level ll = global["log_level"].as<Log_level>();

        // std::string ll1 = global["log_level_1"].as<std::string>();
        // std::cout << "ll1 = '" << ll1 << "'" << std::endl;

        // YAML::Node route = config["route"];
        // if (route)
        //     std::cout << "route section is present" << std::endl;
        // else
        //     std::cout << "route section is NOT present" << std::endl;

        // YAML::Node route2 = route[1];
        // if (route2)
        //     std::cout << "second route is present" << std::endl;
        // else
        //     std::cout << "second route is NOT present" << std::endl;

        // YAML::Node input = route2["input"];
        // if (input)
        //     std::cout << "input in second route is present" << std::endl;
        // else
        //     std::cout << "input in second route is is NOT present" << std::endl;

        // YAML::Node stream = input[0];
        // if (stream)
        //     std::cout << "first stream in input in second route is present" << std::endl;
        // else
        //     std::cout << "first stream input in second route is is NOT present" << std::endl;

        // YAML::Node link = stream["link"];
        // if (link)
        //     std::cout << "link in input in second route is present" << std::endl;
        // else
        //     std::cout << "link in input in second route is NOT present" << std::endl;

        // YAML::Node link0 = link[0];
        // if (link0)
        //     std::cout << "link[0] in input in second route is present" << std::endl;
        // else
        //     std::cout << "link[0] in input in second route is NOT present" << std::endl;

        // YAML::Node host = link0["host"];
        // if (host)
        //     std::cout << "host in link[0] in input in second route is present" << std::endl;
        // else
        //     std::cout << "host in link[0] in input in second route is NOT present" << std::endl;

        // if (host.IsNull())
        //     std::cout << "host value is empty" << std::endl;

        // std::cout << "host = '" << host.as<std::string>() << "'" << std::endl;

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
