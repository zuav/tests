#include <vector>
#include <string>
#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <boost/process/io.hpp>
#include <boost/process/child.hpp>
#include <boost/process/pipe.hpp>
#pragma GCC diagnostic pop


int main(int argc, char *argv[])
{
    if (argc != 1) {
        std::cerr << "Usage: ./a.out executable-file-name" << std::endl;
        return 1;
    }

    bp::pipe p;
    bp::ipstream is;

    std::vector<std::string> outline;
    std::string file(argv[1]);

    //we just use the same pipe, so the output of nm is directly passed as input to c++filt
    bp::child nm(bp::search_path("nm"), file,  bp::std_out > p);
    bp::child filt(bp::search_path("c++filt"), bp::std_in < p, bp::std_out > is);

    std::string line;
    while (filt.running() && std::getline(is, line)) //when nm finished the pipe closes and c++filt exits
        outline.push_back(line);

    nm.wait();
    filt.wait();

    for (const auto& s : outline)
        std::cout << s << std::endl;

    return 0;
}
