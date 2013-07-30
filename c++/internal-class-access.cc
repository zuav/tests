class Foo {
public:
    Foo(int);

private:
    class Bar;

    int foo;
    Bar *b;
};


class Foo::Bar {
public:
    Bar(Foo&);

private:
    int bar;
};



Foo::Foo(int i)
    : foo(i),
      b(new Bar(*this))
{
}

Foo::Bar::Bar(Foo& f)
    :bar(f.foo)
{
}

int main()
{
    Foo f(1);

    return 0;
}
