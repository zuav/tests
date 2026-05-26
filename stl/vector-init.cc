#include <vector>
#include <iostream>


int main()
{
    std::vector<int> v1 { 10 };
    std::vector<int> v2(10);
    std::vector<int> v3 = std::vector<int>(11);
    std::vector<int> v4 { -1, -1 };
    std::vector<int> v5 { std::vector<int>::size_type(3), -1 };
    std::vector<int> v6(3, -1);

    std::cout << "v1.size(): " << v1.size() << "; v1[0]: " << v1[0] << std::endl
              << "v2.size(): " << v2.size() << "; v2[0]: " << v2[0] << std::endl
              << "v3.size(): " << v3.size() << "; v3[0]: " << v3[0] << std::endl
              << "v4.size(): " << v4.size() << "; v4[0]: " << v4[0] << "; v4[1]: " << v4[1] << std::endl
              << "v5.size(): " << v5.size() << std::endl
              << "v6.size(): " << v6.size() << "; v6[0]: " << v6[0] << "; v6[1]: " << v6[1] << "; v6[2]: " << v6[2] << std::endl;

    return 0;
}
