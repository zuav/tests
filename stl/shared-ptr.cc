#include <memory>
#include <iostream>

struct Free {
    void operator()(int* p) const
        {
            std::cout << "custom delete called; p = " << p << std::endl;
        }
};


int main()
{
    std::shared_ptr<int> p(0, Free());

    return 0;
}
