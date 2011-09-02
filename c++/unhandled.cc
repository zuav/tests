int foo()
{
	throw "Unhandled excpetion";
}

void bar()
{
	foo();
}

//int var = foo();

int main()
{
	bar();

	return 0;
}
