int bar()
{
    return -5;
}

int main()
{
    if ((int i = bar()) < 0) {
        std::cout << "less than zero" << std::endl;
        return i;
    }

    return 0;
}
