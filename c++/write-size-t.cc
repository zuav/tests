#include <fstream>

int main()
{
    size_t v = 172;
    std::ofstream f("/tmp/zzz-172-cc.bin");
    f.write(reinterpret_cast<char*>(&v), sizeof(v));

    return 0;
}
