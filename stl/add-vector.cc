#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v1;
    for (int i=0; i<4; ++i)
        v1.push_back(i);
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::vector<int> v2;
    for (int i=4; i<8; ++i)
        v2.push_back(i);
    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::copy(v2.begin(), v2.end(), std::back_insert_iterator<std::vector<int> >(v1));
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
