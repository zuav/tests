#include <vector>
#include <iostream>


int main()
{
    std::vector<int> v1 { 10 };
    std::vector<int> v2(10);
    std::vector<int> v3 = std::vector<int>(11);

    std::cout << "v1.size(): " << v1.size() <<";  v1[0]: " << v1[0] << std::endl
              << "v2.size(): " << v2.size() <<"; v2[0]: " << v2[0]  << std::endl
              << "v3.size(): " << v3.size() <<"; v3[0]: " << v3[0]  << std::endl;

    return 0;
}
