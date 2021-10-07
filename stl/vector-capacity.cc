#include <vector>
#include <iostream>


int main()
{
    std::vector<int> v;
    std::vector<int> v10(10);

    std::cout << "default vector capacity: " << v.capacity()   << std::endl
              << "vector(10) capacity:     " << v10.capacity() << std::endl;

    return 0;
}
