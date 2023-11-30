#include <string>
#include <istream>
#include <iostream>
#include <fstream>


class Config {
public:
    Config(const std::string& file);
    Config(std::istream&);

    void print();

private:
    Config();

    void parse_file(std::istream&);

    int i1;
    int i2;
    int i3;
};


Config::Config()
    : i1(1),
      i2(2),
      i3(3)
{
}


Config::Config(std::istream& is)
    : Config()
{
    parse_file(is);
}



Config::Config(const std::string&)
    : Config()
{
    std::ifstream is;
    parse_file(is);
}


void Config::print()
{
    std::cout << i1 << ','
              << i2 << ','
              << i3 << std::endl;
}


void Config:: parse_file(std::istream&)
{
}


int main()
{
    // Config c1;
    // c1.print();

    std::ifstream is;
    Config c2(is);
    c2.print();

    Config c3("some-file");
    c3.print();
}
