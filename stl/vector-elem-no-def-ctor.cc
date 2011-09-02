#include <vector>

struct Elem {
    int i;

    Elem(int ii) : i(ii) {}
};

int main()
{
    std::vector<Elem> v;

    v.push_back(Elem(0));
//     v[1] = Elem(1);

    return 0;
}
