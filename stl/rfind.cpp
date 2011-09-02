#include <string>
#include <iostream>

int main()
{
    std::string key    = "gandalf@bakery.ithilien.unison.local";
    std::string domain = "bakery.ithilien.unison.local";

    std::string::size_type ind = key.rfind(domain);

    std::cout << "key = " << key << std::endl
              << "domain = " << domain << std::endl
              << "ind = " << ind << std::endl
              << "key[ind-1] = " << key[ind-1] << std::endl
              << "key[ind-1] == '@' " << (key[ind-1] == '@') << std::endl;

    return 0;
}
