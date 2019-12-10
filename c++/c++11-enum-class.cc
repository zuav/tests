enum class Code : int {
    ok,
    error
};

int main()
{
    return static_cast<int>(Code::ok);
}
