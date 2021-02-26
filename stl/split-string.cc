#include <string>
#include <sstream>
#include <vector>
#include <iostream>


int main()
{
    std::string str = "1,2,3,4,5,6";
    std::vector<int> vect;

    std::stringstream ss(str);

    for (int i; ss >> i;) {
        vect.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }

    for (std::size_t i=0; i<vect.size(); ++i)
        std::cout << vect[i] << std::endl;


    std::string str2 = "1,2,3,4,abc,5,6";
    std::vector<int> vect2;

    std::stringstream ss2(str2);

    while (ss2.good()) {
        std::string substr;
        std::getline(ss2, substr, ',');
        try {
            int i = std::stoi(substr);
            vect2.push_back(i);
        }
        catch (const std::invalid_argument&) {
            std::cerr << "error: bad payload value: " << substr << std::endl;
        }
    }

    for (std::size_t i=0; i<vect2.size(); ++i)
        std::cout << vect2[i] << std::endl;

    return 0;
}
