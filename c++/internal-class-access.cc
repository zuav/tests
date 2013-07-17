class Foo {
public:
    Foo(int);

private:
    int foo;

    class Bar {
    public:
        Bar(Foo&);

    private:
        int bar;
    };
};


Foo::Foo(int i)
    : foo(i)
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
