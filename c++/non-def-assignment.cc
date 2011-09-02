struct S {
    int i1;
    int i2;

    S(int i11, int i22) : i1(i11), i2(i22) {}

    //    template <int I>
    //S& operator=(int);

     S& operator=(int) { i1 = 0; i2 = 0; }
    template <int N>
    void reset();
};

//template <int N>
//S& S::operator=<0>(int i = N) { i1 = 0; i2 = 0; }

template <>
void S::reset<0>() { i1 = 0; i2 = 0; }


int main()
{
    S s1(1, 1), s2(2, 2);

    s1.reset();
    s2 = s1;
}


