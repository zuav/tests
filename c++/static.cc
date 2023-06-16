class Foo {
public:
    static Foo& instance()
        {
            static Foo foo;
            return foo;
        }

private:
    Foo() {}
};

int main()
{
    Foo& f = Foo::instance();

    return 0;
}
