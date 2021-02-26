#include <iostream>
#include <fstream>
#include <vector>
#include <string>


int main(int argc, char *argv[])
{
    const std::string fname { argv[1] };

    std::ifstream fin;
    fin.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fin.open(fname);
    fin.seekg(0, std::ios::end);
    const std::ifstream::pos_type len = fin.tellg();
    if (len == 0)
        throw std::runtime_error("Cannot read file " + fname + " (it is empty");

    std::vector<char> buf(len);
    fin.seekg(0, std::ios::beg);
    fin.read(buf.data(), len);

    return 0;
}
