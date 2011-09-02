#include <boost/regex.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " test-to-match" << std::endl;
        exit(1);
    }

    try  {
        std::string text = argv[1];
        std::string regx = "([0-9]+)\\.([0-9]+)\\.([0-9]+)";
        std::cout << "Expression:  \"" << regx << "\"\n";
        std::cout << "Text:        \"" << text << "\"\n";

        boost::regex e(regx);
        boost::smatch what;

        if (!boost::regex_match(text, what, e)) {
            std::cout << "** No Match found **\n";
        } else {
            unsigned i;
            std::cout << "** Match found **\n   Sub-Expressions:\n";
            for(i = 0; i < what.size(); ++i)
                std::cout << "      $" << i << " = \"" << what[i] << "\"\n";
        }
    }
    catch (std::exception& exc) {
        std::cerr << "exception: " << exc.what() << std::endl;
        exit(2);
    }

    return 0;
}
