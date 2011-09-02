#include <iostream>

struct List {
    int         num;
    int         order;
    const char *p[];
};

int main()
{
    for (int i=0; i<100; ++i) {

        char *ptr = new char [sizeof(List) + sizeof(char*) * 10];
        List *l = reinterpret_cast<List *>(ptr);

        l->num = 10;
        l->order = i;

        l->p[0] = "0";
        l->p[1] = "1";
        l->p[2] = "2";
        l->p[3] = "3";
        l->p[4] = "4";
        l->p[5] = "5";
        l->p[6] = "6";
        l->p[7] = "7";
        l->p[8] = "8";
        l->p[9] = "9";

        std::cout<< l->num << ", " << l->order << ":  ";

        for (int j=0; j<l->num; ++j)
            std::cout << " " << l->p[j];

        std::cout << std::endl;

        delete [] ptr;
    }

    return 0;
}
